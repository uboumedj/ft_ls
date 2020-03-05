/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manipulation.c                                :+:      :+:    :+:   */
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
	t_file			*child;

	file = data->file_list;
	while (file)
	{
		if ((data->flags->up_r || is_requested_file(&data, file)) && ft_strcmp(file->name, ".") != 0)
			ft_printf("%s%c\n", file->name, file->type == DT_DIR ? ':' : 0);
		child = file->child;
		while (child)
		{
			if (data->flags->a || (child->name)[0] != '.')
				ft_printf("%s\n", child->name);
			child = child->next;
		}
		if (data->flags->up_r || data->file_request)
		{
			child = file->child;
			while (child)
			{
				if ((data->flags->a || (child->name)[0] != '.') &&
					child->child)
				{
					ft_putchar('\n');
					print_files_recursively(data, child->child);
				}
				child = child->next;
			}
		}
		file = file->next;
	}
}

void	print_files_recursively(t_data *data, t_file *child)
{
	t_file			*file;
	char			*parent_path;

	file = child;
	parent_path = get_file_path(child->parent);
	ft_printf("%s:\n",	parent_path);
	free(parent_path);
	while (file)
	{
		if (data->flags->a || (file->name)[0] != '.')
			ft_printf("%s\n", file->name);
		file = file->next;
	}
	file = child;
	while (file)
	{
		if (data->flags->up_r &&
			(data->flags->a || (file->name)[0] != '.') &&
			file->child)
		{
			ft_putchar('\n');
			print_files_recursively(data, file->child);
		}
		file = file->next;
	}
}