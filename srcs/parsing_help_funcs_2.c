/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help_funcs_2.c                        	   :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:49:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:18 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		get_time(t_file **file, t_data *data)
{
	char		*path;
	struct stat	buffer;

	path = get_file_path(*file);
	lstat(path, &buffer);
	free(path);
	if (data->flags->c)
		(*file)->time = buffer.st_ctime;
	else if (data->flags->u)
		(*file)->time = buffer.st_atime;
	else
		(*file)->time = buffer.st_mtime;
}

void		get_more_attributes(t_file **file)
{
	char		*path;
	struct stat	buffer;

	path = get_file_path(*file);
	lstat(path, &buffer);
	free(path);
	(*file)->size = buffer.st_size;
	(*file)->blocks = buffer.st_blocks;
	(*file)->user = buffer.st_uid;
	(*file)->group = buffer.st_gid;
	(*file)->links = buffer.st_nlink;
}