/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/11 15:18:00 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define DEBUG_MAP "test.txt"

int g_fd;

int			sum(int x, int y, t_fil *data)
{
    int		i;
	int		j;
	int		res;

	res = 0;
    j = 0;
	while (j < data->t_y)
	{
		i = 0;
		while (i < data->t_x)
		{
			if (data->t[j][i] == '*')
			{
				res += (data->map[j + y][i + x] >= 1) ? data->map[j + y][i + x] : 0;
			}
			i++;
		}
		j++;
	}
	return (res);
}

int			check(int x, int y, t_fil *data)
{
	int		i;
	int     j;
	int		cross;

	if (x + data->t_x > data->x || y + data->t_y > data->y )
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

t_fil		*place(t_fil *data)
{
	int		i;
	int		j;
	int		min;

	j = 0;
    min = M_INT;
	while (data->t_y + j <= data->y)
	{
		i = 0;
		while (data->t_x + i <= data->x)
		{
			if (check(i, j, data) && sum(i, j, data) < min)
			{
               // write(g_fd, "eeee\n", 5);
				min = sum(i, j, data);
                dprintf(g_fd, "min %d\n", min);
				data->min_x = i;
                data->min_y  = j;
			}
			i++;
		}
		j++;
	}
	free_piece(data);
	return (data);
}

void         print_res(t_fil *data)
{
    ft_putnbr(data->min_y);
    ft_putchar(' ');
    ft_putnbr(data->min_x);
    ft_putchar('\n');
}

	// 		while (j < data->y)
	// 		{
	// 			dprintf(g_fd, "%d|%s|\n", j, data->map[j]);
	// 			j++;
	// 		}
	// 		j = 0;
    // dprintf(g_fd, "%d %d\n", data->min_y, data->min_x);


void         find_player(char *line, t_fil *data)
{
    if (ft_strstr(line, "$$$ exec ") )
     {
         if (ft_strstr(line, "eprusako"))
        {
            data->p = "oO";
            data->e = "xX";
        }
        else
        {
            data->e = "oO";
            data->p = "xX";
        }
     }
}

void	     play_game(int fd , char *line, t_fil *data)
{
    while (1)
	{
		get_next_line(fd, &line);
		if (!line)
			break;
        if (ft_strstr(line, "Plateau ") )
            malloc_map(fd, line, data);
        if (ft_strstr(line, "Piece "))
        {
            malloc_token(fd, line, data);
            print_res(place(data));
			//dprintf(1, "%d %d\n", data->min_y, data->min_x);
			dprintf(g_fd, "%d %d\n", data->min_y, data->min_x);
            data->min_y = 0;
            data->min_x = 0;
          //  data->i++;
            // int j = 0;
        // int i = 0;
        // while (j < data->y)
        // {
        //     i = 0;
        //     while (i < data->x)
        //     {
        //         dprintf(g_fd, "%d ", data->map[j][i]);
        //         i++;
        //     }
        //     dprintf(g_fd, "\n");
        //     j++;
        // }
		// 	write(g_fd, "dddd\n", 5);
			free_piece(data);
			free_map(data);
        }
		ft_strdel(&line);
	}	
 //   free(line);
//    printf("WOW! %d %d \n", data.min_y, data.min_x);
}

int          main(void)
{
    t_fil   data;
    char    *line;

	g_fd = open(DEBUG_MAP, O_WRONLY|O_TRUNC);
    int     fd = 0;
    line = NULL;
    ft_bzero(&data, sizeof(t_fil));
  
   // fd = open("testi", O_RDONLY);
	while (get_next_line(fd, &line) && !ft_strstr(line, "$$$ exec "))
	{
		ft_strdel(&line);
	}
    find_player(line, &data);
    play_game(fd, line, &data);
}

                