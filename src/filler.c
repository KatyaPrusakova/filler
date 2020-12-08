/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/08 15:00:20 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// char    *filler(char **s)
// {
//     char *ss = "8 1";
//    if (s[0] == ss)
//         return (ss);
//     printf("THIS IS FILLER\n  %s", ss);
//     return (ss);
// }

int         puterror(int i)
{
    if (i == 0)
        exit (0);
    return (0);
}

int         get_token(char *line, t_fil *data)
{
    if (data->raz < data->t_y)
    {
        ft_strcpy(data->t[data->raz], line);
        data->raz++;
        return (1);
    }
    else 
        return (0);
    return (0);
}

void         malloc_token(char *line, t_fil *data)
{
    int     i;

    i = 0;
    while (*line != ' ')
        line++;
    line++;
    data->t_y = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    data->t_x = ft_atoi(line);
    if (!(data->t = (char**)ft_memalloc(sizeof(char*) * data->t_y + 1)))
        puterror(0);
    while (i < data->t_y)
        data->t[i++] = (char*)ft_memalloc(sizeof(char) * data->t_x + 1);
}

void         malloc_map(char *line, t_fil *data)
{
    int     i;

    i = 0;
    while (*line != ' ')
        line++;
    line++;
    data->y = ft_atoi(line);
    while (ft_isdigit(*line))
        line++;
    data->x = ft_atoi(line);
    if (!(data->map = (char**)ft_memalloc(sizeof(char*) * data->y + 1)))
        puterror(0);
    while (i < data->y)
        data->map[i++] = (char*)ft_memalloc(sizeof(char) * data->x + 1);
}

int         is_valid(int i, int j, t_fil *data)
{
    if (i >= 0 && j >= 0 && i <= data->x && j <= data->y &&!ft_strchr(O, data->map[j][i]) && !ft_strchr(X, data->map[j][i]))
        return (1);
    return (0);
}

int          fill_it(int i, int j, char r, t_fil *data)
{
     if (is_valid(i, j, data))
    {
        data->map[j][i] = r;
        //solve_it(i, j, r, data);
        return (1);
    }
    return (0);
}

void         solve_it(int i, int j, char fill, t_fil *data)
{
    while (j < data->y)
    {
        i++;
        while (i < data->x)
        {
            if (is_valid(i, j, data))
            {
                data->map[j][i] = fill;
                fill++;
            }
            i++;
        }
        j++;
    }
}

void        find_best(int i, int j, t_fil *data)
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
int         full_fill_it(int i, int j, char r, t_fil *data)
{
    int tj;
    int ti;
    char c;

    
    tj = j;
    ti = i;
    j = tj;
    i = ti;
    c = r;
    while (i < data->x)
    {
        if (fill_it(i, j, r, data))
           r++;
        i++;
    }
    j = tj;
    i = ti;
    r = c;
    while (j < data->y)
    {
        if(fill_it(i, j, r, data))
            r++;
        j++;
    }
    j = tj;
    i = ti;
    r = c;
    while (i < data->x && j < data->y)
    {
        if (fill_it(i, j, r, data))
           r++;
        i++;
        j++;
    }
    j = tj;
    i = ti;
    r = c;
    while (i >= 0 && j >= 0)
    {
        if (fill_it(i, j, r, data))
           r++;
        i--;
        j--;
    }
    j = tj;
    i = ti;
    r = c;
    while (i >= 0)
    {
        if (fill_it(i, j, r, data))
           r++;
        i--;
    }
    j = tj;
    i = ti;
    r = c;
    while (j >= 0)
    {
        if (fill_it(i, j, r, data))
           r++;
        j--;
    }
    j = tj;
    i = ti;
    r = c;
    while (i < data->x && j >= 0)
    {
        if (fill_it(i, j, r, data))
           r++;
        i++;
        j--;
    }
    j = tj;
    i = ti;
    r = c;
    while (j < data->y && i >= 0)
    {
        if (fill_it(i, j, r, data))
           r++;
        j++;
        i--;
    }
    return (0);
}

int         ft_can_fit(int i, int j, t_fil *data)
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
            if (ft_strchr(data->e, data->map[j][i]) && data->t[jj][ii] == '*')
            {
               return (0);
            }
            if (ft_strchr(data->p, data->map[j][i]) && data->t[jj][ii] == '*')
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
     //   printf("answer a |%d| %d %d %d %d \n", a, final_j, final_i, data->answer_y, data->answer_x);
        find_best(data->answer_x, data->answer_y, data);
        data->min_x = final_i;
        data->min_y = final_j;
        return (1);
    }
    return (0);
}

int        find_answer(int j, int i, t_fil *data)
{

 //   printf("find player %s\n", data->p);
    while (j < data->y)
    {
        i = 0;
        while (i < data->x)
        {
            if (ft_can_fit(i, j, data))
            {
                data->answer_x = i;
                data->answer_y = j;
            }
            i++;
        }
        j++;
    }
    return (0);
}

int          find_on_map_player(int j, int i, t_fil *data)
{
    data->p = data->player == 1? "oO" : "xX";
    data->e = data->enemy == 1? "oO" : "xX";

    while (j < data->y)
    {
        i = 0;
        while (i < data->x)
        {
            if (ft_strchr(data->p, data->map[j][i]))
            {
                data->p_x = i;
                data->p_y = j;
            }
            if (ft_strchr(data->e, data->map[j][i]))
            {
                data->e_x = i;
                data->e_y = j;               
                full_fill_it(data->e_x, data->e_y, data->i + '0', data);
            }
            i++;
        }
        j++;
    }
    return (1);
}

void         find_player(char *line, t_fil *data)
{
    char *s;
    
     if (ft_strstr(line, "eprusako"))
     {
        s = ft_strchr(line, 'p');
        data->player = s[1] - '0';
        data->enemy = data->player == 1 ? 2 : 1;
        // printf("%d|| data->player ||\n", data->player);
     }
    
}
// (void)
int          main(int argc, char **argv)
{
    t_fil   data;
    char    *line;
    int     fd;
    
    line = NULL;
    ft_bzero(&data, sizeof(t_fil));
   argc = 0;
  
  if ((fd = open(argv[1], O_RDONLY)) == -1)
	  puterror(0);
	while (get_next_line(fd, &line) > 0)
     // while (get_next_line(0, &line) > 0)
	{
     //   printf("%d|| %s ||\n", argc, line);
        
        if (ft_strstr(line, "$$$ exec"))
            find_player(line, &data);
        if (ft_strstr(line, "Plateau ") && !data.x)
            malloc_map(line, &data);
        if (ft_isdigit(line[0]) && !data.end)
            data.map[data.i++] = ft_strsub(line, 4, data.x);
        else if (data.end)
        {
            data.i = 0;
            if (!get_token(line, &data))
                break;
        }
        if (ft_strstr(line, "Piece "))
        {
            malloc_token(line, &data);   
            data.end = 1;
        }
    //    argc++;
		ft_strdel(&line);
	}
    ft_strdel(&line);
    find_on_map_player(0, 0, &data);
 //   print_map(0, &data);
   // full_put_token(&data);
 //   print_token(0, &data);
    find_answer(0, 0, &data);
//    printf("WOW! %d %d \n", data.min_y, data.min_x);
    ft_putnbr(data.min_y);
	ft_putchar(' ');
	ft_putnbr(data.min_x);
	ft_putchar('\n');
    
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