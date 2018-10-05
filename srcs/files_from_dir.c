/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_from_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:49:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:18 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		files_from_dir(char *directory, t_data **data)
{
	DIR				*dir;
	struct dirent	*dp;
	t_files			*fname;

	if ((dir = opendir(directory)) == NULL)
		return (0);
	(*data)->names = NULL;
	while ((dp = readdir(dir)) != NULL)
	{
		fname = new_file(dp->d_name);
		fname->next = (*data)->names;
		(*data)->names = fname;
	}
	closedir(dir);
	orderfiles(&((*data)->names), (*data)->flags->r);
	return (1);
}

void	print_files(t_data *data)
{
	t_files			*file;

	file = data->names;
	while (file != NULL)
	{
		if (data->flags->a || (file->str)[0] != '.')
			ft_printf("%s\n", file->str);
		file = file->next;
	}
}
