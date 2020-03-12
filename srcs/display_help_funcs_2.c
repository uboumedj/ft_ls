/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help_funcs_2.c        		                :+:      :+:    :+:   */
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

short	compute_padding(t_file *dir, char *datatype)
{
	t_file	*child;
	short	padding;
	short	length;

	child = dir->child;
	padding = 0;
	while (child)
	{
		if (ft_strcmp(datatype, "links") == 0)
			length = number_length(child->links);
		else if (ft_strcmp(datatype, "size") == 0)
			length = number_length(child->size);
		if (length > padding)
			padding = length;
		child = child->next;
	}
	return (padding);
}

short	compute_single_files_padding(t_file *file, char *datatype)
{
	short	padding;
	short	length;
	t_file	*parser;

	parser = file;
	padding = 0;
	while (parser)
	{
		if (parser->type != DT_DIR)
		{
			if (ft_strcmp(datatype, "links") == 0)
				length = number_length(parser->links);
			else if (ft_strcmp(datatype, "size") == 0)
				length = number_length(parser->size);
			if (length > padding)
				padding = length;
		}
		parser = parser->next;
	}
	return (padding);
}

short	number_length(int number)
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
	int 	j;

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