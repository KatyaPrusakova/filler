/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:39:09 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/11 15:21:23 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define VALID	"XxOo"
# define X		"Xx"
# define O		"Oo"
# define M_INT	 2147483647

 
typedef	struct		s_fil
{
	int				**map;
	char			**t;
	int				t_x;
	int				t_y;
	int				end;
	int				x;
	int				y;
	char			*p;
	char			*e;
	int				e_x;
	int				e_y;
	int				answer_x;
	int				answer_y;
	int				i;
	int				raz;
	int				min_x;
	int				min_y;
	int				next_step;
}					t_fil;



/*
** ------ FILLER.C ------
*/

void        		solve_it(int i, int j, char fill, t_fil *data);

/*
** ------ MALLOC_FREE.C ------
*/

void				copy_map(char *line, int y, t_fil *data);
int					puterror(int i);
int         		get_token(char *line, t_fil *data);
void        		malloc_token(int fd, char *line, t_fil *data);
void        		malloc_map(int fd, char *line, t_fil *data);
void        		get_coord(int *x, int *y, char *line);
/*
** ------ TOOLS.C ------
*/

int          		numbers_to_map(int i, int j, t_fil *data);
int          		create_map(int j, int i, t_fil *data);
void		 		make_map(int x, int y, t_fil *data);
void				make_map2(int c, int x, int y, t_fil *data);


void		free_map(t_fil *data);
void		free_piece(t_fil *data);

#endif
