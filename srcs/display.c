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
	t_file			*child;

	file = data->file_list;
	while (file)
	{
		if (data->flags->up_r && ft_strcmp(file->name, ".") != 0)
			ft_printf("%s%c\n", file->name, file->type == DT_DIR ? ':' : 0);
		print_direct_children(file, data);
		if (data->flags->up_r)
		{
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
		file = file->next;
	}

}

void	print_direct_children(t_file *file, t_data *data)
{
	t_file *child;

	child = file->child;
	while (child)
	{
		if (data->flags->a || (child->name)[0] != '.')
			ft_printf("%s\n", child->name);
		child = child->next;
	}
}

void	print_files_recursively(t_data *data, t_file *file)
{
	t_file			*child;
	char			*file_path;

	file_path = get_file_path(file);
	ft_printf("\n%s:\n", file_path);
	free(file_path);
	print_direct_children(file, data);
	child = file->child;
	while (child)
	{
		if (data->flags->up_r &&
			(data->flags->a || (child->name)[0] != '.') &&
			child->child)
		{
			print_files_recursively(data, child);
		}
		child = child->next;
	}
}