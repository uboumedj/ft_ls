/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:29:07 by uboumedj          #+#    #+#             */
/*   Updated: 2018/05/23 19:01:47 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/inc/libft.h"

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

#endif
