/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:29:07 by uboumedj          #+#    #+#             */
/*   Updated: 2018/10/05 16:58:35 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/inc/libft.h"
# include <sys/types.h>
# include <dirent.h>

typedef struct		s_flags
{
	char			l;
	char			up_r;
	char			a;
	char			r;
	char			t;
}					t_flags;

typedef struct		s_files
{
	char			*str;
	struct s_files	*next;
}					t_files;

typedef struct		s_data
{
	t_flags			*flags;
	char			*flaglist;
	t_files			*names;
}					t_data;

void				error_option(t_data **data, char c);
int					files_from_dir(char *directory, t_data **data);
t_files				*new_file(char *data);
void				print_files(t_data *data);
void				orderfiles(t_files **names, char order);

#endif
