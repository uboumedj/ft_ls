/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_files		*new_file(char *data)
{
	t_files		*new;

	if (!(new = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	new->str = data;
	new->next = NULL;
	return (new);
}

static void	swap_next(t_files **a)
{
	char		*temp;

	temp = (*a)->str;
	(*a)->str = (*a)->next->str;
	(*a)->next->str = temp;
}

void		orderfiles(t_files **names, char order)
{
	int			check;
	t_files		*inc;

	check = 1;
	while (check == 1)
	{
		check = 0;
		inc = *names;
		while (inc->next != NULL)
		{
			if ((ft_strcmp(inc->str, inc->next->str) > 0 && !order)
				|| (ft_strcmp(inc->str, inc->next->str) < 0 && order))
			{
				swap_next(&inc);
				check = 1;
			}
			inc = inc->next;
		}
	}
}
