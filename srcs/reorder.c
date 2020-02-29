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
    if ((*data)->flags->t)
        order_alphabetically(data);
    else
        order_alphabetically(data);
}

void		order_alphabetically(t_data **data)
{
	int			ordered;
	int			descending;
	t_file		*file;

	ordered = 1;
	descending = (*data)->flags->r;
	while (ordered == 1)
	{
		ordered = 0;
		file = (*data)->file_list;
		while (file->next)
		{
			if ((ft_strcmp(file->name, file->next->name) > 0 && !descending)
				|| (ft_strcmp(file->name, file->next->name) < 0 && descending))
			{
				swap_with_next(file);
				ordered = 1;
			}
			else
				file = file->next;
		}
		rewind_file_list(data);
	}
}
