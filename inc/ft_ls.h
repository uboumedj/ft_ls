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
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

# define SUCCESS 1
# define FAILURE 0
# define VALID_FLAGS "lRartcu"

typedef struct		s_flags
{
	char			l;
	char			up_r;
	char			a;
	char			r;
	char			t;
	char			c;
	char			u;
}					t_flags;

typedef struct		s_file
{
	char			*name;
	unsigned char	type;
	char			*full_path;
	time_t			time;
	off_t			size;
	blkcnt_t		blocks;
	uid_t			user;
	gid_t			group;
	nlink_t			links;
	mode_t			permissions;
	struct s_file	*parent;
	struct s_file	*child;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct		s_data
{
	t_flags			*flags;
	char			**file_request;
	t_file			*file_list;
}					t_data;


/*
** Data structure initialisation
*/

int					initialise_data(t_data **data);
int     			initialise_flags(t_data **data);
int					initialise_file_requests(t_data **data, int length);


/*
** Arguments parsing
*/

int					parse_arguments(t_data **data, int argc, char **argv);
int					save_file_request(t_data **data, int argc, char *arg);
int					read_argument(t_data **data, char *arg);
int					parse_option(t_data **data, char *arg);
int     			is_valid_flag(char *valid_flags, char c);
void				error_option(t_data **data, char c);
void				error_unknown_file(char *name);


/*
** Current directory parsing (no file request)
*/

t_file				*new_file(void);
int					get_files_data(char *directory, t_data **data);
void				create_parent(t_data **data, char *directory);
void				save_entry_data(t_data **data, t_file **file_list,
													struct dirent *dir_entry);
int					need_children_data(t_data **data, t_file *file);
int					get_children_data(t_data **data, t_file **child);
void				get_more_attributes(t_file **file, t_data *data);


/*
** File requests parsing
*/

char				*get_file_path(t_file *file);
int					is_requested_file(t_data *data, t_file *file);
void				get_requested_files(t_data **data);
int					file_found_in_current_dir(char *name, t_data **data);
int					check_other_path(char **name, t_data **data);
int					determine_path_length(t_file *file);
void				add_dir_to_path(char **path, t_file **dir, int *i);
int					get_specific_file(char *path, char *file, t_data **data);
void				add_specific_file(char *path, char *file, t_data **data,
													struct dirent *dir_entry);


/*
** File display functions
*/

void				print_files(t_data *data);
void				print_files_recursively(t_data *data, t_file *file);
void				print_requested_files(t_data *data);
int					print_single_files(t_file *file, t_data *data);
void				print_directories(t_file *file, t_data *data,
													int single_file_presence);
void				print_direct_children(t_file *file, t_data *data);
void				print_children_recursively(t_file *file, t_data *data);
void				print_link(t_file *file);
void				print_total_blocksize(t_file *file, t_data *data);
void				print_extended_info(t_file *file, short links_padding, short size_padding);
void				initialise_permissions(t_file *file, char *permissions);
char				file_type_symbol(t_file *file);
short				number_length(int number);
short				compute_padding(t_file *dir, char *datatype);
short				compute_single_files_padding(t_file *file, char *datatype);
void				format_date(t_file *file, char *date);
void				print_id_as_string(int id);


/*
** File reorder functions
*/

int					compare_files(t_file *file_1, t_file *file_2, t_data *data);
int					compare_file_names(t_file *file_1, t_file *file_2);
int					compare_file_times(t_file *file_1, t_file *file_2);
void				swap_with_next(t_file *file);
void				rewind_file_list(t_file **file_list);
void				place_in_order(t_file **file, t_file **list, t_data *data);
void				insert_file(t_file **before, t_file **file, t_file **after);
void				insert_beginning(t_file **f, t_file **start, t_data *data);
void				insert_end(t_file **file, t_file **end, t_data *data);
void				rewind_structure(t_file **file_list);


/*
** Free functions
*/

void				free_memory(t_data *data);
void				free_file_list(t_file *file);
void				free_file_requests(char **file_request);

#endif
