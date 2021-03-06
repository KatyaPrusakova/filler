/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:32:51 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/18 23:06:57 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Function to calculate the sum of values if token is placed
** at the spot x, y. The minimum value is saved as optimal,
** and closest spot to place the piece to the enemy.
*/

int				sum(int x, int y, t_fil *data)
{
	int			i;
	int			j;
	int			res;

	res = 0;
	j = 0;
	while (j < data->t_y)
	{
		i = 0;
		while (i < data->t_x)
		{
			if (data->t[j][i] == '*')
			{
				res += (data->map[j + y][i + x] >= 1) ? \
				data->map[j + y][i + x] : 0;
			}
			i++;
		}
		j++;
	}
	return (res);
}

/*
** Function to check if the token overlaping the player only in one 
** spot where token is '*' and token not overlapping enemy pieces.
*/

int				check(int x, int y, t_fil *data)
{
	int			i;
	int			j;
	int			cross;

	if (x + data->t_x > data->x || y + data->t_y > data->y)
		return (0);
	j = 0;
	cross = 0;
	while (j < data->t_y)
	{
		i = 0;
		while (i < data->t_x)
		{
			if (data->t[j][i] == '*')
			{
				if (data->map[j + y][i + x] == -2)
					return (0);
				else if (data->map[j + y][i + x] == -1)
					cross++;
			}
			i++;
		}
		j++;
	}
	return (cross == 1 ? 1 : 0);
}

/*
** Function to find best position and coordinates given as output of the
** program: where to place the token. It goes through all map and data->t_y + j
** lenght is used in order not to go too far in the map and segfault.
*/

t_fil			*place(t_fil *data)
{
	int		i;
	int		j;
	int		min;

	j = 0;
	min = M_INT;
	check_corners(data);
	while (data->t_y + j <= data->y)
	{
		i = 0;
		while (data->t_x + i <= data->x)
		{
			if (check(i, j, data) && sum(i, j, data) < min)
			{
				min = sum(i, j, data);
				data->min_x = i;
				data->min_y = j;
			}
			i++;
		}
		j++;
	}
	free_piece(data);
	return (data);
}

#define DEBUG_MAP "test.txt"
int	g_fd;

void			check_corners(t_fil *data)
{
	int			x;
	int			y;
	int			flag;

	x = 0;
	y = 0;
	flag = 0;
	g_fd = open(DEBUG_MAP, O_WRONLY|O_TRUNC);
	
	while (y < data->t_y)
	{
		while (x < data->t_x)
		{
			if (check_y(x, y, 0, data) && y == 0)
				dprintf(1, "%d %d\n", data->min_y, data->min_x);
			if (check_x(x, y, 0, data) && x == 0)
				dprintf(1, "%d %d\n", data->min_y, data->min_x);
			x++;
		}
		y++;
	}
}

int			check_y(int x, int y, int flag, t_fil *data)
{
	int		i;
	int		j;

	i = data->t_x;
	j = data->t_y;
	while (x-- > 0)
	{
		if (data->t[j + y][i + x] == '*' && data->map[y][x])
			flag++;
	}
	// if (flag == 1 and no other '*')
	// {
	// 	data->min_x = i;
	// 	data->min_y = j;
	// }
}

int			check_x(int x, int y, int flag, t_fil *data)
{
	int		i;
	int		j;

	i = data->t_x;
	j = data->t_y;
	while (y-- > 0)
	{
		if (data->t[j + y][i + x] == '*' && data->map[y][x])
			flag++;
	}
}

/*
** Main function to play the game. It loops while the VM is running.
** Everytime there is "Plateau" on stdin it starts to read the map, if
** there is "Piece" on stdin it starts to read the token and find solution.
*/

void			play_game(int fd, char *line, t_fil *data)
{
	while (1)
	{
		get_next_line(fd, &line);
		if (!line)
			break ;
		if (ft_strstr(line, "Plateau "))
			malloc_map(fd, line, data);
		if (ft_strstr(line, "Piece "))
		{
			malloc_token(fd, line, data);
			print_res(place(data));
			data->min_y = 0;
			data->min_x = 0;
			free_piece(data);
			free_map(data);
		}
		ft_strdel(&line);
	}
}
