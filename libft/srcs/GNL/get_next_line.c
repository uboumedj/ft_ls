/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:09:56 by uboumedj          #+#    #+#             */
/*   Updated: 2018/05/15 18:20:05 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	src_newline(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	buff_trim(char *buff, int i)
{
	buff = ft_strcpy(buff, buff + i + 1);
	while (BUFF_SIZE - i - 1 < BUFF_SIZE)
	{
		buff[BUFF_SIZE - i - 1] = '\0';
		i--;
	}
}

static int	fill_buff(const int fd, char **line, char **buff, int i)
{
	int		rd;
	char	*temp;

	while ((rd = read(fd, *buff, BUFF_SIZE)) > 0)
	{
		i = src_newline(*buff);
		if (i == -1)
		{
			temp = ft_strjoin(*line, *buff);
			free(*line);
			ft_bzero(*buff, BUFF_SIZE);
			*line = ft_strdup(temp);
			free(temp);
		}
		else
		{
			temp = ft_strjoin_i(*line, *buff, i);
			free(*line);
			*line = ft_strdup(temp);
			buff_trim(*buff, i);
			free(temp);
			return (1);
		}
	}
	return (i == -1 ? 1 : rd);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buff;
	int			i;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	*line = ft_strnew(0);
	i = 0;
	if (!buff)
		buff = ft_strnew(BUFF_SIZE);
	else
	{
		i = src_newline(buff);
		if (i != -1)
		{
			*line = ft_strsub(buff, 0, i);
			buff_trim(buff, i);
			return (1);
		}
		else if (buff[0] != '\0' && i == -1)
			*line = ft_strdup(buff);
		else if (buff[0] == '\0')
			i = 0;
	}
	ft_bzero(buff, BUFF_SIZE);
	return (fill_buff(fd, line, &buff, i));
}
