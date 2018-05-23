/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:37:32 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 14:44:09 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	**ft_strarrdup(char **str)
{
	char	**res;
	size_t	len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	if (!(res = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
