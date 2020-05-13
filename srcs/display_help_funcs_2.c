/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help_funcs_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	file_type_symbol(t_file *file)
{
	if (file->type == DT_DIR)
		return ('d');
	else if (file->type == DT_LNK)
		return ('l');
	else if (file->type == DT_FIFO)
		return ('p');
	else if (file->type == DT_BLK)
		return ('b');
	else if (file->type == DT_CHR)
		return ('c');
	else if (file->type == DT_SOCK)
		return ('s');
	else if (file->type == DT_UNKNOWN)
		return ('?');
	else
		return ('-');
}

short	*compute_padding(t_file *dir)
{
	t_file	*child;
	short	*padding;

	child = dir->child;
	padding = (short *)ft_memalloc(6 * sizeof(short));
	while (child)
	{
		padding[0] = ft_max(num_length(child->links), padding[0]);
		padding[1] = ft_max(ft_strlen(child->user), padding[1]);
		padding[2] = ft_max(ft_strlen(child->group), padding[2]);
		padding[3] = ft_max(num_length(child->size), padding[3]);
		if (child->type == DT_CHR || child->type == DT_BLK)
		{
			padding[4] = ft_max(num_length(major(child->dev)), padding[4]);
			padding[5] = ft_max(num_length(minor(child->dev)), padding[5]);
		}
		child = child->next;
	}
	if (padding[4] && padding[5])
		padding[3] = ft_max((padding[4] + padding[5] + 2), padding[3]);
	return (padding);
}

short	*compute_single_files_padding(t_file *file)
{
	t_file	*parser;
	short	*padding;

	parser = file;
	padding = (short *)ft_memalloc(6 * sizeof(short));
	while (parser)
	{
		if (parser->type != DT_DIR)
		{
			padding[0] = ft_max(num_length(parser->links), padding[0]);
			padding[1] = ft_max(ft_strlen(parser->user), padding[1]);
			padding[2] = ft_max(ft_strlen(parser->group), padding[2]);
			padding[3] = ft_max(num_length(parser->size), padding[3]);
			if (parser->type == DT_CHR || parser->type == DT_BLK)
			{
				padding[4] = ft_max(num_length(major(parser->dev)), padding[4]);
				padding[5] = ft_max(num_length(minor(parser->dev)), padding[5]);
			}
		}
		parser = parser->next;
	}
	if (padding[4] && padding[5])
		padding[3] = ft_max((padding[4] + padding[5] + 2), padding[3]);
	return (padding);
}

short	num_length(int number)
{
	short result;

	result = 1;
	while (number > 0)
	{
		number /= 10;
		if (number > 0)
			result++;
	}
	return (result);
}

void	format_date(t_file *file, char *date)
{
	char	*raw_date;
	time_t	curr_time;
	int		i;
	int		j;

	raw_date = ctime(&file->time);
	i = 0;
	j = 4;
	while (i < 7)
	{
		date[i] = raw_date[j];
		i++;
		j++;
	}
	curr_time = time(NULL);
	if (curr_time - file->time > 15552000)
		j += 8;
	while (i < 12)
	{
		date[i] = raw_date[j];
		i++;
		j++;
	}
	date[i] = '\0';
}
