/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                        	           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:49:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:18 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		get_files_data(char *directory, t_data **data)
{
	DIR				*dir_stream;
	struct dirent	*next_dir_entry;
	int				result;

	result = SUCCESS;
	if ((dir_stream = opendir(directory)) == NULL)
		result = FAILURE;
	else
	{
		create_parent(data, directory);
		while ((next_dir_entry = readdir(dir_stream)) != NULL)
		{
			save_entry_data(data, &((*data)->file_list), next_dir_entry);
		}
		closedir(dir_stream);
	}
	return (result);
}

void	create_parent(t_data **data, char *directory)
{
	t_file	*new;

	new = new_file();
	new->name = ft_strdup(directory);
	new->type = DT_DIR;
	new->parent = NULL;
	new->child = NULL;
	place_in_order(&new, &(*data)->file_list, *data);
}

void	save_entry_data(t_data **data, t_file **file_list,
												struct dirent *dir_entry)
{
	t_file	*file;

	file = new_file();
	file->name = ft_strdup(dir_entry->d_name);
	file->type = dir_entry->d_type;
	file->length = dir_entry->d_reclen;
	file->child = NULL;
	file->parent = *file_list;
	if ((*data)->flags->t || (*data)->flags->l)
		get_time(&file, *data);
	if ((*data)->flags->l)
		get_more_attributes(&file);
	if (need_children_data(data, file))
		get_children_data(data, &file);
	place_in_order(&file, &(*file_list)->child, *data);
}

int		get_children_data(t_data **data, t_file **file)
{
	DIR				*dir_stream;
	struct dirent	*next_dir_entry;
	char			*directory;
	int				result;

	directory = get_file_path(*file);
	result = SUCCESS;
	if ((dir_stream = opendir(directory)) == NULL)
		result = FAILURE;
	else
	{
		while ((next_dir_entry = readdir(dir_stream)) != NULL)
		{
			save_entry_data(data, file, next_dir_entry);
		}
		closedir(dir_stream);
	}
	free(directory);
	return (result);
}