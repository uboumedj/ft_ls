/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int     initialise_data(t_data **data)
{
    int     error_check;

    error_check = SUCCESS;
	if (!((*data) = (t_data *)malloc(sizeof(t_data))))
    {
		error_check = FAILURE;
    }
	(*data)->valid_flags = "lRart";
	(*data)->file_list = NULL;
    if (!(initialise_flags(data)))
    {
        error_check = FAILURE;
    }
	return (error_check);
}

int     initialise_flags(t_data **data)
{
	if (!((*data)->flags = (t_flags *)malloc(sizeof(t_flags))))
		return (FAILURE);
	(*data)->flags->l = 0;
	(*data)->flags->up_r = 0;
	(*data)->flags->a = 0;
	(*data)->flags->r = 0;
	(*data)->flags->t = 0;
    return (SUCCESS);
}

void	parse_flags(t_data **data, int argc, char **argv)
{
	int		i;
	if (argc > 1)
	{
		i = 1;
		while (i < argc && argv[i][0] == '-')
		{
			read_argument(data, argv[i]);
			i++;
		}
	}
}

void	read_argument(t_data **data, char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		if (!(is_valid_flag((*data)->valid_flags, arg[i])))
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

int     is_valid_flag(char *valid_flags, char c)
{
	int i;

	i = 0;
	while (valid_flags[i])
	{
		if (valid_flags[i] == c)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}