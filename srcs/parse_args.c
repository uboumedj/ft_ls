/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                         			     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		parse_arguments(t_data **data, int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				if (!(parse_option(data, argv[i])))
					return (FAILURE);
			}
			else
			{
				if (!(save_file_request(data, argc, argv[i])))
					return (FAILURE);
			}
			i++;
		}
	}
	return (SUCCESS);
}

int		save_file_request(t_data **data, int argc, char *file)
{
	int i;

	if (!((*data)->file_request))
	{
		if (!(initialise_file_requests(data, argc)))
			return (FAILURE);
	}
	i = 0;
	while ((*data)->file_request[i])
	{
		i++;
	}
	(*data)->file_request[i] = ft_strdup(file);
	return (SUCCESS);
}

int		parse_option(t_data **data, char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		if (!(is_valid_flag(VALID_FLAGS, arg[i])))
		{
			error_option(data, arg[i]);
			return (FAILURE);
		}
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
			else if (arg[i] == 'c')
				(*data)->flags->c = 1;
			else if (arg[i] == 'u')
				(*data)->flags->u = 1;
		}
		i++;
	}
	return (SUCCESS);
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