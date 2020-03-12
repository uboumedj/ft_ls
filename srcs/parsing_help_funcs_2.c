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

void		get_more_attributes(t_file **file, t_data *data)
{
	struct stat	buffer;

	lstat((*file)->full_path, &buffer);
	if (data->flags->c)
		(*file)->time = buffer.st_ctime;
	else if (data->flags->u)
		(*file)->time = buffer.st_atime;
	else
		(*file)->time = buffer.st_mtime;
	if (data->flags->l)
	{
		(*file)->size = buffer.st_size;
		(*file)->blocks = buffer.st_blocks;
		(*file)->user = buffer.st_uid;
		(*file)->group = buffer.st_gid;
		(*file)->links = buffer.st_nlink;
		(*file)->permissions = buffer.st_mode;
	}
}