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
	new->next = NULL;
	return (new);
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