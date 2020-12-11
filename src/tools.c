/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:52:16 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/11 16:04:02 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int g_fd;

int			create_map(int j, int i, t_fil *data)
{
	while (j < data->y)
	{
		i = 0;
		while (i < data->x)
		{
			if (data->map[j][i] == 0)  
				make_map(i, j, data);
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
					make_map2(c, i, j, data);
				i++;
			}
			j++;
		}
		c++;
	}
	return (1);
}

void		make_map(int x, int y, t_fil *data)
{
	if ((x - 1 >= 0 && y - 1 >= 0 && data->map[y - 1][x - 1] == -2) ||
			(y - 1 >= 0 && data->map[y - 1][x] == -2) ||
			(x + 1 < data->x && y - 1 >= 0 && data->map[y - 1][x + 1] == -2) ||
			(x - 1 >= 0 && data->map[y][x - 1] == -2) ||
			(x + 1 < data->x && data->map[y][x + 1] == -2) ||
			(x - 1 >= 0 && y + 1 < data->y && data->map[y + 1][x - 1] == -2) ||
			(y + 1 < data->y && data->map[y + 1][x] == -2) ||
			(x + 1 < data->x && y + 1 < data->y && data->map[y + 1][x + 1] == -2))
		data->map[y][x] = 1;
}

void		make_map2(int c, int x, int y, t_fil *data)
{
	if ((x - 1 >= 0 && y - 1 >= 0 && data->map[y - 1][x - 1] == c) ||
		(y - 1 >= 0 && data->map[y - 1][x] == c) ||
		(x + 1 < data->x && y - 1 >= 0 && data->map[y - 1][x + 1] == c) ||
		(x - 1 >= 0 && data->map[y][x - 1] == c) ||
		(x + 1 < data->x && data->map[y][x + 1] == c) ||
		(x - 1 >= 0 && y + 1 < data->y && data->map[y + 1][x - 1] == c) ||
		(y + 1 < data->y && data->map[y + 1][x] == c) ||
		(x + 1 < data->x && y + 1 < data->y && data->map[y + 1][x + 1] == c))
			data->map[y][x] = c +  1;
}
