/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:29:07 by uboumedj          #+#    #+#             */
/*   Updated: 2018/07/19 16:05:49 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/inc/libft.h"
# include <sys/types.h>
# include <dirent.h>

typedef struct	s_flags
{
	char		l;
	char		up_r;
	char		a;
	char		r;
	char		t;
}				t_flags;

typedef struct	s_data
{
	t_flags		*flags;
	char		*flaglist;
}				t_data;

void			error_option(t_data **data, char c);
int				files_from_dir(char *directory, t_data *data);

#endif
