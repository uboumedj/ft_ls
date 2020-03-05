/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                         :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void        reorder_files(t_data **data)
{
	int		descending;
	t_file	**file_list;

	descending = (*data)->flags->r;
	file_list = &((*data)->file_list);
    if ((*data)->flags->t)
        order_alphabetically(file_list, descending);
    else
        order_alphabetically(file_list, descending);
}

void		order_alphabetically(t_file **file_list, int descending)
{
	int			ordered;
	int			compare;
	t_file		*file;

	ordered = 1;
	while (ordered == 1)
	{
		ordered = 0;
		file = *file_list;
		if (file)
		{
			while (file->next)
			{
				compare = compare_file_names(file, file->next);
				if ((compare > 0 && !descending) || (compare < 0 && descending))
				{
					swap_with_next(file);
					ordered = 1;
				}
				else
					file = file->next;
			}
			rewind_file_list(file_list);
		}
	}
	order_children(file_list, descending);
}

void		order_children(t_file **file_list, int descending)
{
	t_file *file;

	if (*file_list)
	{
		file = *file_list;
		while (file)
		{
			if (file->child)
			{
				order_alphabetically(&(file->child), descending);
			}
			file = file->next;
		}
	}
}