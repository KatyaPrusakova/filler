/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/11 09:57:39 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define DEBUG_MAP "test.txt"

int g_fd;

int          fill_it(int i, int j, char r, t_fil *data)
{
     if (is_valid(i, j, data))
    {
        data->map[j][i] = r;
        return (1);
    }
    return (0);
}

int			sum(int x, int y, t_fil *data)
{
    int		i;
	int		j;
	int		res;

	res = 0;
    j=0;
    write(g_fd, "sum\n", 5);
	while (j < data->t_y)
	{
		i = 0;
		while (i < data->t_x)
		{
			if (data->t[j][i] == '*')
			{
				res += (data->map[j + y][i + x] >= '1') ? data->map[j + y][i + 1] : 0;
			}
			i++;
		}
		j++;
	}
    write(g_fd, "fin_sum\n", 9);
	return (res);
}

int			check(int x, int y, t_fil *data)
{
	int		i;
	int     j;
	int		cross;

	if (x + data->t_x > data->x || y + data->t_y > data->y )
		return (0);
	j = -1;
	cross = 0;
    write(g_fd, "check\n", 7);
	while (++j < data->t_y)
	{
		i = -1;
		while (++i < data->t_x)
		{
			if (data->t[j][i] == '*')
			{
				if (ft_strchr(data->e, data->map[j + y][i + x]))
					return (0);
				else if (ft_strchr(data->p, data->map[j + y][i + x]))
					cross++;
			}
		}
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
                write(g_fd, "eeee\n", 5);
				min = sum(i, j, data);
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

int          ft_can_fit(int i, int j, t_fil *data)
{
    int jj;
    int ii;
    int a;
    int fake_i;
    int final_j;
    int final_i;
    int min;

    jj = 0;
    ii = 0;
    a = 0;
    fake_i = i;
    final_j = j;
    final_i = i;

    while (jj < data->t_y && data->t_y + j < data->y)
    {
        ii = 0;
        fake_i = i;
        while (ii < data->t_x && i < data->x)
        {
            if (ft_strchr(data->p, data->map[j][i]) && data->t[jj][ii] == '*')
            {
                if (sum(i, j, data) < min)
				    min = sum(i, j, data);
                a++;
            }
            i++;
            ii++;
        }
        j++;
        jj++;
    }


 //   print_map(0, data); answer точки соприкосновения однако нам нужны изначальные j i
   
    if (a == 1)
    {
        
		dprintf(g_fd, "best is %d %d %d\n", a, final_j, final_i);
        data->min_x = final_i;
        data->min_y = final_j;
        return (1);
    }
    return (0);
}



void          print_res(t_fil *data)
{
    ft_putnbr(data->min_y);
    ft_putchar(' ');
    ft_putnbr(data->min_x);
    ft_putchar('\n');
}

int          find_answer(int j, int i, t_fil *data)
{
    // while (j < data->y)
    // {
        i = 0;
    //     while (i < data->x)
    //     {
            print_res(place(data));
    //         {
    //            break;
	// 			//dprintf(g_fd, "find_answer %d %d\n", data->answer_y, data->answer_x);
    //         }
            
    //         i++;
    //     }
    //     j++;
    // }
	 j = 0;
			while (j < data->y)
			{
				dprintf(g_fd, "%d|%s|\n", j, data->map[j]);
				j++;
			}
			j = 0;
    dprintf(g_fd, "%d %d\n", data->min_y, data->min_x);
    return (0);
}

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

// printf("%d|| data->player ||\n", data->player);

void	     play_game(int fd , char *line, t_fil *data)
{
    while (1)
	{
		get_next_line(fd, &line);
		//write(g_fd, "eeee\n", 5);
		if (!line)
			break;
     //   printf("%d|| %s ||\n", argc, line);
        if (ft_strstr(line, "Plateau ") )
            malloc_map(fd, line, data);
        if (ft_strstr(line, "Piece "))
        {
            malloc_token(fd, line, data);
            data->i = 0;
            find_answer(0, 0, data);
            
			//dprintf(1, "%d %d\n", data->min_y, data->min_x);
			dprintf(g_fd, "%d %d\n", data->min_y, data->min_x);
			write(g_fd, "dddd\n", 5);
			
			
			free_piece(data);
			free_map(data);
        }
		ft_strdel(&line);
	}
	
 //   free(line);
//    printf("WOW! %d %d \n", data.min_y, data.min_x);
    
}

//add if no option put value data->end to 1

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

                