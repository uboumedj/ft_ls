/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2018/07/19 16:06:28 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static int	is_flag(char *flaglist, char c)
{
	int i;

	i = 0;
	while (flaglist[i])
	{
		if (flaglist[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	check_flags(t_data **data, char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		if (!(is_flag((*data)->flaglist, arg[i])))
			error_option(data, arg[i]);
		else
		{
			if (arg[i] == 'R')
				(*data)->flags->up_r = 1;
			else if (arg[i] == 'a')
				(*data)->flags->a = 1;
			else if (arg[i] == 'l')
				(*data)->flags->l = 1;
			else if (arg[i] == 'r')
				(*data)->flags->r = 1;
			else if (arg[i] == 't')
				(*data)->flags->t = 1;
		}
		i++;
	}
}

static int	init_data(t_data **data)
{
	if (!((*data) = (t_data *)malloc(sizeof(t_data))))
		return (0);
	(*data)->flaglist = "lRart";
	if (!((*data)->flags = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	(*data)->flags->l = 0;
	(*data)->flags->up_r = 0;
	(*data)->flags->a = 0;
	(*data)->flags->r = 0;
	(*data)->flags->t = 0;
	return (1);
}

int			main(int argc, char **argv)
{
	t_data			*data;
	int				i;

	if (!(init_data(&data)))
		return (0);
	if (argc > 1)
	{
		i = 1;
		while (i < argc && argv[i][0] == '-')
		{
			check_flags(&data, argv[i]);
			i++;
		}
	}
	files_from_dir(".", data);
	free(data->flags);
	free(data);
	return (0);
}
