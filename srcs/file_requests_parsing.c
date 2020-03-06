/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_requests_parsing.c               	           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:49:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:18 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		get_requested_files(t_data **data)
{
	char	**requests;
	int		i;

	requests = (*data)->file_request;
	if (requests)
	{
		i = 0;
		while (requests[i])
		{
			if (!(get_files_data(requests[i], data)))
			{
				if (!(check_other_path(&requests[i], data)))
					error_unknown_file(requests[i]);
			}
			i++;
		}
	}
}

int			check_other_path(char **name, t_data **data)
{
	char	*path;
	char	*file;
	int		i;
	int		result;

	result = SUCCESS;
	if (ft_strchr(*name, '/') == 0)
	{
		if (!(get_specific_file(".", *name, data)))
			result = FAILURE;
	}
	else
	{
		i = ft_strlen(*name) - 1;
		while ((*name)[i] && (*name)[i] != '/')
			i--;
		path = ft_strsub(*name, 0, i + 1);
		file = ft_strsub(*name, i + 1, ft_strlen(*name) - i - 1);
		if (!(get_specific_file(path, file, data)))
			result = FAILURE;
		free(file);
		free(path);
	}
	return (result);
}

int			get_specific_file(char *path, char *file, t_data **data)
{
	DIR				*dir_stream;
	struct dirent	*next_dir_entry;
	int				result;

	result = FAILURE;
	if ((dir_stream = opendir(path)) != NULL)
	{
		while ((next_dir_entry = readdir(dir_stream)) != NULL)
		{
			if (ft_strcmp(next_dir_entry->d_name, file) == 0)
			{
				add_specific_file(path, file, data, next_dir_entry);
				result = SUCCESS;
				break;
			}
		}
		closedir(dir_stream);
	}
	return (result);
}

void		add_specific_file(char *path, char *file, t_data **data,
													struct dirent *dir_entry)
{
	t_file		*req_file;

	req_file = new_file();
	req_file->name = ft_strjoin(!ft_strcmp(path, ".") ? "" : path, file);
	req_file->type = dir_entry->d_type;
	req_file->length = dir_entry->d_reclen;
	req_file->child = NULL;
	req_file->parent = NULL;
	req_file->next = (*data)->file_list;
	if ((*data)->file_list != NULL)
		(*data)->file_list->prev = req_file;
	(*data)->file_list = req_file;
}