/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:52:16 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/13 22:36:39 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Filling the map value to make heat map, in
** order to know the distance between the player and enemy
** i - 1  |  i - 1  |  i - 1
** j - 1  |         |  j + 1
** -------------------------
**        |    i    |       
** j - 1  |    j    |  j + 1
** -------------------------
** i + 1  |         |  i + 1
** j - 1  |  i + 1  |  j + 1
*/

int			create_map(int j, int i, t_fil *data)
{
	while (j < data->y)
	{
		i = 0;
		while (i < data->x)
		{
			if (data->map[j][i] == 0)
				add_num(i, j, data);
			i++;
		}
		j++;
	}
	numbers_to_map(0, 0, data);
	return (1);
}

int			numbers_to_map(int i, int j, t_fil *data)
{
	int		c;

	c = 1;
	while (c < (data->y + data->x))
	{
		j = 0;
		while (j < data->y)
		{
			i = 0;
			while (i < data->x)
			{
				if (data->map[j][i] == 0)
					add_num_all_map(c, i, j, data);
				i++;
			}
			j++;
		}
		c++;
	}
	return (1);
}

void		add_num(int x, int y, t_fil *data)
{
	if ((x - 1 >= 0 && y - 1 >= 0 && data->map[y - 1][x - 1] == -2) ||
		(y - 1 >= 0 && data->map[y - 1][x] == -2) ||
		(x + 1 < data->x && y - 1 >= 0 && data->map[y - 1][x + 1] == -2) ||
		(x - 1 >= 0 && data->map[y][x - 1] == -2) ||
		(x + 1 < data->x && data->map[y][x + 1] == -2) ||
		(x - 1 >= 0 && y + 1 < data->y && data->map[y + 1][x - 1] == -2) ||
		(y + 1 < data->y && data->map[y + 1][x] == -2) ||
		(x + 1 < data->x && y + 1 < data->y && \
		data->map[y + 1][x + 1] == -2))
		data->map[y][x] = 1;
}

void		add_num_all_map(int c, int x, int y, t_fil *data)
{
	if ((x - 1 >= 0 && y - 1 >= 0 && data->map[y - 1][x - 1] == c) ||
		(y - 1 >= 0 && data->map[y - 1][x] == c) ||
		(x + 1 < data->x && y - 1 >= 0 && data->map[y - 1][x + 1] == c) ||
		(x - 1 >= 0 && data->map[y][x - 1] == c) ||
		(x + 1 < data->x && data->map[y][x + 1] == c) ||
		(x - 1 >= 0 && y + 1 < data->y && data->map[y + 1][x - 1] == c) ||
		(y + 1 < data->y && data->map[y + 1][x] == c) ||
		(x + 1 < data->x && y + 1 < data->y && data->map[y + 1][x + 1] == c))
		data->map[y][x] = c + 1;
}

void		get_coord(int *x, int *y, char *line)
{
	while (*line != ' ')
		line++;
	line++;
	*y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	*x = ft_atoi(line);
}
