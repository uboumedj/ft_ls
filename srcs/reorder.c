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

void		place_in_order(t_file **file, t_file **list, int descending)
{
	t_file	*file_list;

	file_list = *list;
	rewind_file_list(&file_list);
	if (!file_list)
	{
		(*file)->next = NULL;
		(*file)->prev = NULL;
	}
	else
	{
		while (file_list && file_list->next && 
				((compare_file_names(*file, file_list) > 0 && !descending) ||
				(compare_file_names(*file, file_list) < 0 && descending)))
		{
			file_list = file_list->next;
		}
		if (!file_list->prev)
			insert_beginning(file, &file_list, descending);
		else if (!file_list->next)
			insert_end(file, &file_list, descending);
		else
			insert_file(&(file_list->prev), file, &file_list);
	}
	*list = *file;
}

void		insert_beginning(t_file **file, t_file **start, int descending)
{
	if ((compare_file_names(*file, *start) > 0 && !descending) ||
			(compare_file_names(*file, *start) < 0 && descending))
	{
		(*file)->prev = *start;
		(*file)->next = (*start)->next;
		(*start)->next = *file;
		if ((*file)->next)
			(*file)->next->prev = *file;
	}
	else
	{
		(*file)->next = *start;
		(*file)->prev = NULL;
		(*start)->prev = *file;
	}
}

void		insert_end(t_file **file, t_file **end, int descending)
{
	if ((compare_file_names(*file, *end) > 0 && !descending) ||
			(compare_file_names(*file, *end) < 0 && descending))
	{
		(*file)->prev = *end;
		(*file)->next = NULL;
		(*end)->next = *file;
	}
	else
	{
		(*file)->next = *end;
		(*file)->prev = (*end)->prev;
		(*end)->prev = *file;
		if ((*file)->prev)
			(*file)->prev->next = *file;
	}
}

void		insert_file(t_file **before, t_file **file, t_file **after)
{
	if (*before)
		(*before)->next = *file;
	(*file)->prev = *before;
	(*file)->next = *after;
	if (*after)
		(*after)->prev = *file;
}