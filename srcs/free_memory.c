/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 17:03:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		free_memory(t_data *data)
{
	free_file_list(data->file_list, data->flags);
	if (data->file_request)
		free_file_requests(data->file_request);
	free(data);
}

void		free_file_list(t_file *file, int flags)
{
	t_file *next;

	while (file)
	{
		next = file->next;
		free_file_list(file->child, flags);
		free(file->name);
		free(file->full_path);
		if (flags & L_FLAG)
		{
			free(file->user);
			free(file->group);
		}
		free(file);
		file = next;
	}
}

void		free_file_requests(char **file_request)
{
	int i;

	i = 0;
	if (file_request)
	{
		while (file_request[i])
		{
			free(file_request[i]);
			i++;
		}
		free(file_request);
	}
}
