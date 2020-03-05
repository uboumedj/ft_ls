/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                        	           :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:49:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:18 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		is_requested_file(t_data **data, t_file *file)
{
	int		i;
	int		found;
	char	*path;

	if (!(*data)->file_request)
		return (FAILURE);
	i = 0;
	found = 0;
	path = get_file_path(file);
	while ((*data)->file_request[i])
	{
		if (ft_strcmp((*data)->file_request[i], path) == 0)
			found = 1;
		i++;
	}
	free(path);
	return (found);
}

int		need_children_data(t_data **data, t_file *file)
{
	int		need;

	need = 0;
	if (file->type == DT_DIR &&
			(is_requested_file(data, file) ||
			((*data)->flags->up_r &&
			ft_strcmp(file->name, "..") != 0 &&
			ft_strcmp(file->name, ".") != 0)))
	{
		need = 1;
	}
	return (need);
}

char	*get_file_path(t_file *file)
{
	char	*path;
	t_file	*parser;
	int		length;
	int		i;
	int		j;

	parser = file;
	length = 0;
	while (parser)
	{
		length += ft_strlen(parser->name) + 1;
		parser = parser->parent;
	}
	if (!(path = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	i = length - 1;
	path[i] = '\0';
	i--;
	parser = file;
	while (parser)
	{
		j = ft_strlen(parser->name) - 1;
		while (j >= 0)
		{
			path[i] = parser->name[j];
			i--;
			j--;
		}
		parser = parser->parent;
		if (parser)
		{
			path[i] = '/';
			i--;
		}
	}
	return (path);
}