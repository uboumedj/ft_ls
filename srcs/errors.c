/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:56:00 by uboumedj          #+#    #+#             */
/*   Updated: 2018/07/19 16:00:10 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	error_option(t_data **data, char c)
{
	free_file_requests((*data)->file_request);
	free((*data)->flags);
	free(*data);
	ft_putstr_fd("./ft_ls: invalid option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ./ft_ls [-Ralrtuc] [file ...]\n", 2);
}

void	error_unknown_file(char *name)
{
	ft_putstr_fd("./ft_ls: cannot access '", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("': No such file or directory\n", 2);
}
