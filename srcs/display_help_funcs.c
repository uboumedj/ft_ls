/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_link(t_file *file)
{
	char buffer[255];

	ft_bzero(buffer, 255);
	readlink(file->full_path, buffer, 255);
	ft_printf(" -> %s", buffer);
}

void	print_total_blocksize(t_file *file)
{
	int		result;
	t_file	*child;

	result = 0;
	child = file->child;
	while (child)
	{
		result += child->blocks;
		child = child->next;
	}
	ft_printf("total %d\n", result / 2);
}

void	print_extended_info(t_file *file, short *padding)
{
	char			permissions[11];
	char			date[13];

	initialise_permissions(file, permissions);
	ft_putstr(permissions);
	ft_printf(" %*ld %-*s %-*s ", padding[0], file->links, padding[1],
					file->user, padding[2], file->group);
	format_date(file, date);
	if (file->type == DT_BLK || file->type == DT_CHR)
		ft_printf(" %*ld, %*ld", padding[4], major(file->dev),
												padding[5], minor(file->dev));
	else
		ft_printf(" %*ld", padding[3], file->size);
	ft_printf(" %s ", date);
}

void	initialise_permissions(t_file *file, char *permissions)
{
	permissions[0] = file_type_symbol(file);
	permissions[1] = (file->permissions & S_IRUSR) ? 'r' : '-';
	permissions[2] = (file->permissions & S_IWUSR) ? 'w' : '-';
	if (file->permissions & S_ISUID)
		permissions[3] = (file->permissions & S_IXUSR) ? 's' : 'S';
	else
		permissions[3] = (file->permissions & S_IXUSR) ? 'x' : '-';
	permissions[4] = (file->permissions & S_IRGRP) ? 'r' : '-';
	permissions[5] = (file->permissions & S_IWGRP) ? 'w' : '-';
	if (file->permissions & S_ISGID)
		permissions[6] = (file->permissions & S_IXGRP) ? 's' : 'S';
	else
		permissions[6] = (file->permissions & S_IXGRP) ? 'x' : '-';
	permissions[7] = (file->permissions & S_IROTH) ? 'r' : '-';
	permissions[8] = (file->permissions & S_IWOTH) ? 'w' : '-';
	if (file->permissions & S_ISVTX)
		permissions[9] = (file->permissions & S_IXOTH) ? 't' : 'T';
	else
		permissions[9] = (file->permissions & S_IXOTH) ? 'x' : '-';
	permissions[10] = '\0';
}
