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

t_file		*new_file(void)
{
	t_file		*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->prev = NULL;
	new->child = NULL;
	new->parent = NULL;
	new->next = NULL;
	return (new);
}

int			compare_files(t_file *file_1, t_file *file_2, t_data *data)
{
	if (data->flags->t)
		return (compare_file_times(file_1, file_2));
	else
		return (compare_file_names(file_1, file_2));
}

int			compare_file_times(t_file *file_1, t_file *file_2)
{
	int compare;

	if (!file_1 || !file_2)
		return (FAILURE);
	compare = file_2->time - file_1->time;
	if (compare == 0)
		return (compare_file_names(file_1, file_2));
	else
		return (compare);
}

int			compare_file_names(t_file *file_1, t_file *file_2)
{
	int i;

	i = 0;
	if (!file_1 || !file_2)
		return (FAILURE);
	while (file_1->name[i] &&
			ft_tolower(file_1->name[i]) == ft_tolower(file_2->name[i]))
	{
		i++;
	}
	return (ft_tolower(file_1->name[i]) - ft_tolower(file_2->name[i]));
}

void		rewind_structure(t_file **file_list)
{
	t_file *file;

	rewind_file_list(file_list);
	file = *file_list;
	while (file)
	{
		if (file->child)
			rewind_structure(&file->child);
		file = file->next;
	}
}