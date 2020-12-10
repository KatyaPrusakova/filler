/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:52:16 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/10 18:37:03 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int         is_valid(int i, int j, t_fil *data)
{
    if (i >= 0 && j >= 0 && i <= data->x && j <= data->y &&!ft_strchr(O, data->map[j][i]) && !ft_strchr(X, data->map[j][i]))
        return (1);
    return (0);
}


int          create_map(int j, int i, t_fil *data)
{
    while (j < data->y)
    {
        i = 0;
        while (i < data->x)
        {
            if (data->map[j][i] == '.')  
                make_map(i, j, data);
            i++;
        }
        j++;
    }
    numbers_to_map(0, 0, data);
    return (1);
}

int          numbers_to_map(int i, int j, t_fil *data)

{
    int c;

    c = 1;
    while (c < (data->y + data->x))
	{
		j = 0;
        while (j < data->y)
        {
            i = 0;
            while (i < data->x)
            {
                if (data->map[j][i] == '.')  
                    make_map2(c + '0', i, j, data);
                i++;
            }
            j++;
        }
       c++;
   }
   // print_map(0, data);
    return (1);
}

void		 make_map(int x, int y, t_fil *data)
{
	if ((x - 1 >= 0 && y - 1 >= 0 && ft_strchr(data->e, data->map[y - 1][x - 1])) ||
			(y - 1 >= 0 && ft_strchr(data->e, data->map[y - 1][x])) ||
			(x + 1 < data->x && y - 1 >= 0 && ft_strchr(data->e, data->map[y - 1][x + 1])) ||
			(x - 1 >= 0 && ft_strchr(data->e, data->map[y][x - 1])) ||
			(x + 1 < data->x && ft_strchr(data->e, data->map[y][x + 1])) ||
			(x - 1 >= 0 && y + 1 < data->y && ft_strchr(data->e, data->map[y + 1][x - 1])) ||
			(y + 1 < data->y && ft_strchr(data->e, data->map[y + 1][x])) ||
			(x + 1 < data->x && y + 1 < data->y && ft_strchr(data->e, data->map[y + 1][x + 1])))
		data->map[y][x] = 1 + '0';
}

void		 make_map2(int c, int x, int y, t_fil *data)
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

