/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help_funcs.c          		                :+:      :+:    :+:   */
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
	char *path;

	if (file->type == DT_LNK)
	{
		ft_bzero(buffer, 255);
		path = get_file_path(file);
		readlink(path, buffer, 255);
		free(path);
		ft_printf(" -> %s", buffer);
	}
}

void	print_total_blocksize(t_file *file, t_data *data)
{
	int		result;
	t_file	*child;

	result = 0;
	child = file->child;
	while (child)
	{
		if (data->flags->a || child->name[0] != '.')
		{
			result += child->blocks;
		}
		child = child->next;
	}
	ft_printf("total %d\n", result / 2);
}

void	print_extended_info(t_file *file)
{
	char permissions[11];

	initialise_permissions(file, permissions);
	ft_printf("%s %ld %ld ", permissions, file->links, file->size);
}

void	initialise_permissions(t_file *file, char *permissions)
{
	int i;

	i = 1;
	permissions[0] = file_type_symbol(file);
	while (i < 10)
	{
		permissions[i] = '-';
		i++;
	}
	permissions[i] = '\0';
}

char	file_type_symbol(t_file *file)
{
	if (file->type == DT_DIR)
		return ('d');
	else if (file->type == DT_LNK)
		return ('l');
	else if (file->type == DT_FIFO)
		return ('p');
	else if (file->type == DT_BLK)
		return ('b');
	else if (file->type == DT_CHR)
		return ('c');
	else if (file->type == DT_SOCK)
		return ('s');
	else if (file->type == DT_UNKNOWN)
		return ('?');
	else
		return ('-');
}