/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:42:27 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 16:24:42 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putlenstr(char *str, int len)
{
	int i;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}