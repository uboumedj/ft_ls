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

int		initialise_data(t_data **data)
{
	int	error_check;

	error_check = SUCCESS;
	if (!((*data) = (t_data *)malloc(sizeof(t_data))))
	{
		error_check = FAILURE;
	}
	(*data)->file_list = NULL;
	(*data)->file_request = NULL;
	(*data)->flags = 0;
	return (error_check);
}

int		initialise_file_requests(t_data **data, int length)
{
	int	i;

	if (!((*data)->file_request = (char **)malloc(sizeof(char *) * length)))
	{
		return (FAILURE);
	}
	i = 0;
	while (i < length)
	{
		(*data)->file_request[i] = NULL;
		i++;
	}
	return (SUCCESS);
}
