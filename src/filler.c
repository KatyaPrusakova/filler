/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/10 21:42:05 by eprusako         ###   ########.fr       */
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

void         find_best(int i, int j, t_fil *data)
{
    int jj;
    int ii;

    jj = data->e_y - data->answer_y;
    ii = data->e_x - data->answer_x;
     while (j < data->y)
    {
        i++;
        while (i < data->x)
        {
            if (ft_isdigit(data->map[j][i]))
            {
                if (!data->i)
                {
                    data->i = jj + ii;
                    data->min_x = data->answer_x;
                    data->min_y = data->answer_y;
                }
                if (data->i && data->i > jj + ii)
                {
                    data->i = jj + ii;
                    data->min_x = data->answer_x;
                    data->min_y = data->answer_y;
                }
            }
            i++;
        }
        j++;
    }
}

int          ft_can_fit(int i, int j, t_fil *data)
{
    int jj;
    int ii;
    int a;
    int fake_i;
    int final_j;
    int final_i;
    
    jj = 0;
    ii = 0;
    a = 0;
    fake_i = i;
    final_j = j;
    final_i = i;
    data->answer_y = j;
    // while (ft_isdigit(data->map[j][i]) && )
    // if (data->map[j][i] && data->t[jj][ii])
    while (jj < data->t_y && j < data->y)
    {
        ii = 0;
        fake_i = i;
        while (ii < data->t_x && i < data->x)
        {
			if (j && data->t_y + j > data->y)
				break;
            if (ft_strchr(data->p, data->map[j][i]) && data->t[jj][ii] == '*' && enemy(i, j, data))
            {
                a++;
                data->answer_x = i;
            }
			
            // data->map[j][i] = data->t[jj][ii];
            i++;
            ii++;
        }
        j++;
        jj++;
    }
 //   print_map(0, data); answer точки соприкосновения однако нам нужны изначальные j i
   
    if (a == 1)
    {
        dprintf(g_fd,"jj |%d| j %d \n", j, jj);
		dprintf(g_fd, "best is %d %d\n", final_j, final_i);
        data->min_x = final_i;
        data->min_y = final_j;
        return (1);
    }
    return (0);
}

int          find_answer(int j, int i, t_fil *data)
{
    while (j < data->y)
    {
        i = 0;
        while (i < data->x)
        {
            if (ft_can_fit(i, j, data))
            {
               break;
				//dprintf(g_fd, "find_answer %d %d\n", data->answer_y, data->answer_x);
            }
            
            i++;
        }
        j++;
    }
	 j = 0;
			while (j < data->y)
			{
				dprintf(g_fd, "%d|%s|\n", j, data->map[j]);
				j++;
			}
			j = 0;
			while (j < data->t_y)
			{
				dprintf(g_fd, "|%s|\n", data->t[j]);
				j++;
			}
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
    // free(line);
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
            //ft_putnbr(data->min_y);
           // ft_putchar(' ');
           // ft_putnbr(data->min_x);
            //ft_putchar('\n');
			dprintf(1, "%d %d\n", data->min_y, data->min_x);
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

void	print_map(int j, t_fil *data)
{
	while (j < data->y)
	{
		printf("|%s|\n", data->map[j]);
		j++;
	}
}

void	print_token(int j, t_fil *data)
{
    printf("|token print|\n");
	while (j < data->t_y)
	{
		printf("|%s|\n", data->t[j]);
		j++;
	}
}

                