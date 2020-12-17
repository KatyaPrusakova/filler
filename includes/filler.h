/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:37:46 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/12 00:10:21 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define VALID	"XxOo"
# define M_INT	 2147483647

typedef	struct		s_fil
{
	int				**map;
	char			**t;
	int				t_x;
	int				t_y;
	int				x;
	int				y;
	char			*p;
	char			*e;
	int				min_x;
	int				min_y;
}					t_fil;

/*
** ------ FILLER.C ------
*/
void				find_player(char *line, t_fil *data);
void				print_res(t_fil *data);
int					puterror(int i);

/*
** ------ MALLOC_FREE.C ------
*/

void				copy_map(char *line, int y, t_fil *data);
void				malloc_token(int fd, char *line, t_fil *data);
void				malloc_map(int fd, char *line, t_fil *data);
void				free_map(t_fil *data);
void				free_piece(t_fil *data);

/*
** ------ TOOLS.C ------
*/

int					numbers_to_map(int i, int j, t_fil *data);
int					create_map(int j, int i, t_fil *data);
void				add_num(int x, int y, t_fil *data);
void				add_num_all_map(int c, int x, int y, t_fil *data);
void				get_coord(int *x, int *y, char *line);

/*
** ------ SOLVER.C ------
*/

int					sum(int x, int y, t_fil *data);
int					check(int x, int y, t_fil *data);
void				play_game(int fd, char *line, t_fil *data);
t_fil				*place(t_fil *data);

#endif
