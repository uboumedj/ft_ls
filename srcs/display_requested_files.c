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
	single_file_presence = print_single_files(file, data);
	print_directories(file, data, single_file_presence);
}

int		print_single_files(t_file *file, t_data *data)
{
	int		count;
	short	links_padding;
	short	size_padding;

	count = 0;
	if (data->flags & L_FLAG)
	{
		links_padding = compute_single_files_padding(file, "links");
		size_padding = compute_single_files_padding(file, "size");
	}
	while (file)
	{
		if (file->type != DT_DIR)
		{
			if (data->flags & L_FLAG)
				print_extended_info(file, links_padding, size_padding);
			ft_printf("%s", file->name);
			if ((data->flags & L_FLAG) && file->type == DT_LNK)
				print_link(file);
			ft_putchar('\n');
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
			if (data->flags & L_FLAG)
				print_total_blocksize(file);
			print_direct_children(file, data);	
			if (data->flags & UP_R_FLAG)
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
		if (((data->flags & A_FLAG) || (child->name)[0] != '.') &&
				child->child)
		{
			print_files_recursively(data, child);
		}
		child = child->next;
	}
}