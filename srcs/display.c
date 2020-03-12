/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c         			                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_files(t_data *data)
{
	t_file			*file;

	file = data->file_list;
	while (file)
	{
		if ((data->flags & UP_R_FLAG) && ft_strcmp(file->name, ".") != 0)
		{
			ft_printf("%s:\n", file->name);
		}
		if (data->flags & L_FLAG)
			print_total_blocksize(file);
		print_direct_children(file, data);
		if (data->flags & UP_R_FLAG)
		{
			print_children_recursively(file, data);
		}
		file = file->next;
	}
}

void	print_direct_children(t_file *file, t_data *data)
{
	t_file	*child;
	short	links_padding;
	short	size_padding;

	child = file->child;
	if (data->flags & L_FLAG)
	{
		links_padding = compute_padding(file, "links");
		size_padding = compute_padding(file, "size");
	}
	while (child)
	{
		if (data->flags & L_FLAG)
			print_extended_info(child, links_padding, size_padding);
		ft_printf("%s", child->name);
		if (data->flags & L_FLAG && child->type == DT_LNK)
			print_link(child);
		ft_putchar('\n');
		child = child->next;
	}
}

void	print_files_recursively(t_data *data, t_file *file)
{
	ft_printf("\n%s:\n", file->full_path);
	if (data->flags & L_FLAG)
		print_total_blocksize(file);
	print_direct_children(file, data);
	print_children_recursively(file, data);
}