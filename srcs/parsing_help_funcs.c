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

int		is_requested_file(t_data *data, t_file *file)
{
	int		i;
	int		found;
	char	*path;

	if (!data->file_request)
		return (FAILURE);
	i = 0;
	found = 0;
	path = get_file_path(file);
	while (data->file_request[i])
	{
		if (ft_strcmp(data->file_request[i], path) == 0)
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
			(is_requested_file(*data, file) ||
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

	length = determine_path_length(file);
	if (!(path = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	path[length - 1] = '\0';
	i = length - 2;
	parser = file;
	while (parser)
	{
		add_dir_to_path(&path, &parser, &i);
	}
	return (path);
}

int		determine_path_length(t_file *file)
{
	int		length;
	t_file	*parser;

	length = 0;
	parser = file;
	while (parser)
	{
		length += ft_strlen(parser->name) + 1;
		parser = parser->parent;
	}
	return (length);
}

void	add_dir_to_path(char **path, t_file **dir, int *i)
{
	int j;

	j = ft_strlen((*dir)->name) - 1;
	while (j >= 0)
	{
		(*path)[*i] = (*dir)->name[j];
		(*i)--;
		j--;
	}
	(*dir) = (*dir)->parent;
	if (*dir)
	{
		(*path)[*i] = '/';
		(*i)--;
	}
}