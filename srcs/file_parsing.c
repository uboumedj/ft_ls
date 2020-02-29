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
	DIR			*dir_stream;

	if ((dir_stream = opendir(directory)) == NULL)
		return (FAILURE);
	read_directory_loop(data, dir_stream);
	closedir(dir_stream);
	return (SUCCESS);
}

void	read_directory_loop(t_data **data, DIR *dir_stream)
{
	struct dirent	*next_dir_entry;

	while ((next_dir_entry = readdir(dir_stream)) != NULL)
	{
		save_entry_data(data, next_dir_entry);
	}
}

void	save_entry_data(t_data **data, struct dirent *dir_entry)
{
	t_file	*current_entry;

	current_entry = new_file();
	current_entry->name = dir_entry->d_name;
	current_entry->type = dir_entry->d_type;
	current_entry->length = dir_entry->d_reclen;
	current_entry->next = (*data)->file_list;
	if ((*data)->file_list != NULL)
	{
		(*data)->file_list->prev = current_entry;
	}
	(*data)->file_list = current_entry;
}

void	print_files(t_data *data)
{
	t_file			*file;

	file = data->file_list;
	while (file != NULL)
	{
		if (data->flags->a || (file->name)[0] != '.')
			ft_printf("%s\n", file->name);
		file = file->next;
	}
}
