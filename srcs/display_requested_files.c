/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_requested_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_requested_files(t_data *data)
{
	t_file			*file;
	int				single_file_presence;

	file = data->file_list;
	single_file_presence = print_single_files(file);
	print_directories(file, data, single_file_presence);
}

int		print_single_files(t_file *file)
{
	int count;

	count = 0;
	while (file)
	{
		if (file->type != DT_DIR)
		{
			ft_printf("%s\n", file->name);
			count = 1;
		}
		file = file->next;
	}
	return (count);
}

void	print_directories(t_file *file, t_data *data, int single_file_presence)
{
	while (file)
	{
		if (file->type == DT_DIR)
		{
			if (single_file_presence || file->prev)
			{
				ft_putchar('\n');
			}
			ft_printf("%s:\n", file->name);
			print_direct_children(file, data);	
			if (data->flags->up_r)
			{
				print_children_recursively(file, data);
			}
		}
		file = file->next;
	}
}

void	print_children_recursively(t_file *file, t_data *data)
{
	t_file *child;

	child = file->child;
	while (child)
	{
		if ((data->flags->a || (child->name)[0] != '.') &&
				child->child)
		{
			print_files_recursively(data, child);
		}
		child = child->next;
	}
}