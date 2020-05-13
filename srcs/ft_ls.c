/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:32:20 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			main(int argc, char **argv)
{
	t_data			*data;

	if (!(initialise_data(&data)))
		return (0);
	if (!(parse_arguments(&data, argc, argv)))
		return (0);
	if (data->file_request)
	{
		get_requested_files(&data);
		rewind_structure(&data->file_list);
		print_requested_files(data);
	}
	else
	{
		get_files_data(".", &data);
		rewind_structure(&data->file_list);
		print_files(data);
	}
	free_memory(data);
	return (0);
}
