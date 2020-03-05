/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_help_funcs.c                              :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	swap_with_next(t_file *file)
{
	t_file *next;

	next = file->next;
	if (file->prev)
	{
		file->prev->next = next;
	}
	next->prev = file->prev;
	file->prev = file->next;
	file->next = next->next;
	file->prev->next = file;
	if (file->next)
	{
		file->next->prev = file;
	}
}

void	rewind_file_list(t_file **file_list)
{
	if (*file_list)
	{
		while ((*file_list)->prev)
		{
			(*file_list) = (*file_list)->prev;
		}
	}
}