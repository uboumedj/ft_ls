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
	free((*data)->flags);
	free(*data);
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ./ft_ls [-Ralrt] [file ...]\n", 2);
	exit(1);
}
