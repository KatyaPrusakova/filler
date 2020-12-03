/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:39:09 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/03 20:21:00 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define X		"Xx"
# define O		"Oo"

typedef	struct		s_fil
{
	int				player;
	int				enemy;
	char			**map;
	char			**t;
	int				t_x;
	int				t_y;
	int				end;
	int				x;
	int				y;
	int				p_x;
	int				p_y;
	int				e_x;
	int				e_y;
	int				i;
	char			min;
}					t_fil;

/*
** ------ FILLER.C ------
*/

void				print_token(int j, t_fil *data);
void				print_map(int j, t_fil *data);
void        		solve_it(int i, int j, char fill, t_fil *data);
int        		full_put_token(t_fil *data);
#endif
