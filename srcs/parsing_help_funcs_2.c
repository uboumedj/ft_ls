/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help_funcs_2.c                             :+:      :+:    :+:   */
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
	if (data->flags & C_FLAG)
		(*file)->time = buffer.st_ctime;
	else if (data->flags & U_FLAG)
		(*file)->time = buffer.st_atime;
	else
		(*file)->time = buffer.st_mtime;
	if (data->flags & L_FLAG)
	{
		(*file)->size = buffer.st_size;
		(*file)->blocks = buffer.st_blocks;
		(*file)->user = get_user_name(buffer.st_uid);
		(*file)->group = get_group_name(buffer.st_gid);
		(*file)->links = buffer.st_nlink;
		(*file)->permissions = buffer.st_mode;
		if ((*file)->type == DT_BLK || (*file)->type == DT_CHR)
			(*file)->dev = buffer.st_rdev;
	}
}

char		*get_user_name(uid_t id)
{
	struct passwd	*user;
	char			*name;

	user = getpwuid(id);
	if (!user || !user->pw_name)
		name = ft_itoa(id);
	else
		name = ft_strdup(user->pw_name);
	return (name);
}

char		*get_group_name(gid_t id)
{
	struct group	*grp;
	char			*name;

	grp = getgrgid(id);
	if (!grp || !grp->gr_name)
		name = ft_itoa(id);
	else
		name = ft_strdup(grp->gr_name);
	return (name);
}
