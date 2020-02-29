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

# define SUCCESS 1
# define FAILURE 0

typedef struct		s_flags
{
	char			l;
	char			up_r;
	char			a;
	char			r;
	char			t;
}					t_flags;

typedef struct		s_file
{
	char			*name;
	unsigned char	type;
	unsigned short	length;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_data
{
	t_flags			*flags;
	char			*valid_flags;
	t_file			*file_list;
}					t_data;

/*
** Data structure initialisation
*/

int					initialise_data(t_data **data);
int     			initialise_flags(t_data **data);

/*
** Arguments parsing
*/

void				parse_flags(t_data **data, int argc, char **argv);
void				read_argument(t_data **data, char *arg);
int     			is_valid_flag(char *valid_flags, char c);

/*
** Directory stream manipulation
*/

void				save_entry_data(t_data **data, struct dirent *dir_entry);
void				read_directory_loop(t_data **data, DIR *dir_stream);
void				error_option(t_data **data, char c);
void				swap_with_next(t_file *file);
void				rewind_file_list(t_data **data);
void				reorder_files(t_data **data);
void				order_alphabetically(t_data **data);
int					get_files_data(char *directory, t_data **data);
t_file				*new_file(void);
void				print_files(t_data *data);

#endif
