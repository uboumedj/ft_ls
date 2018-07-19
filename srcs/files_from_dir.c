/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_from_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:49:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/07/19 16:15:28 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		files_from_dir(char *directory, t_data *data)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	if ((dir = opendir(directory)) == NULL)
		return (0);
	while ((dp = readdir(dir)) != NULL)
	{
		i = 0;
		if (dp->d_name[0] != '.' || data->flags->a)
		{
			while (dp->d_name[i])
				ft_putchar(dp->d_name[i++]);
			ft_putchar('\n');
		}
	}
	closedir(dir);
	return (1);
}
