/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/02 22:55:48 by eprusako         ###   ########.fr       */
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

void         get_token(char *line, t_fil *data)
{
    if (ft_strstr(line, "*"))
    {
        data->t[data->t_y] = line;
        data->t_y++;
    }
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
    data->t_y = 0;
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

int         is_valid(int i, int j, char c, t_fil *data)
{
    if (i >= 0 && j >= 0 && j <= data->y && j <= data->y &&!ft_strchr(O, c) && !ft_strchr(X, c))
        return (1);
    return (0);
}

// from enemy plus one everytime its not end off map 

int         fill_it(int i, int j, t_fil *data)
{
    int    temp;

    temp = j - 1;
    while (temp >= 0)
    {
        if (is_valid(i, temp, data->map[temp][i], data))
        {
            data->map[temp][i] = data->i + '0';
            solve_it(i, temp, data->i, data);
        }
        temp--;
    }
    temp = j + 1;
    while (temp < data->y)
    {
        if (is_valid(i, temp, data->map[temp][i], data))
        {
            data->map[temp][i] = data->i + '0';
            solve_it(i, temp, data->i, data);
        }
        temp++;
    }
    temp = i - 1;
    while (temp >= 0)
    {
        if (is_valid(temp, j, data->map[j][temp], data))
        {
            data->map[j][temp] = data->i + '0';
            solve_it(temp, j, data->i, data);
        }
        temp--;
    }
    if (is_valid(i + 1, j, data->map[j][i + 1], data))
    {
        data->map[j][i + 1] = data->i + '0';
    }
    if (is_valid(i + 1, j + 1, data->map[j + 1][i + 1], data))
    {
        data->map[j + 1][i + 1] = data->i + '0';
    }
    if (is_valid(i - 1, j - 1, data->map[j - 1][i - 1], data))
    {
        data->map[j - 1][i - 1] = data->i + '0';
    }
    if (is_valid(i + 1, j - 1, data->map[j - 1][i + 1], data))
    {
        data->map[j - 1][i + 1] = data->i + '0';
    }
    if (is_valid(i - 1, j + 1, data->map[j + 1][i - 1], data))
    {
        data->map[j + 1][i - 1] = data->i + '0';
    }
    return (0);
}

void         solve_it(int i, int j, int fill, t_fil *data)
{
    while (j < data->y)
    {
        i++;
        while (i < data->x)
        {
            if (is_valid(i, j, data->map[j][i], data))
            {
                data->map[j][i] = fill + '0';
                fill++;
            }
            i++;
        }
        j++;
    }
}

void         find_the_spot(int j, int i, t_fil *data)
{
    char    *p;
    char    *e;

    p = data->player == 1? "oO" : "xX";
    e = data->enemy == 1? "oO" : "xX";
    
    while (j < data->y)
    {
        i = 0;
        while (i < data->x)
        {
            if (ft_strchr(p, data->map[j][i]))
            {
                data->p_x = i;
                data->p_y = j;
            }
            if (ft_strchr(e, data->map[j][i]))
            {
                data->e_x = i;
                data->e_y = j;
                fill_it(i, j, data);
            }
            i++;
        }
        j++;
    }
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
  //  while (get_next_line(0, &line) > 0)
	while (get_next_line(fd, &line) > 0)
	{
        printf("%d|| %s ||\n", argc, line);
        if (ft_strstr(line, "Piece "))
        {
            data.end = 1;
            malloc_token(line, &data);   
        }
        if (ft_strstr(line, "$$$ exec"))
            find_player(line, &data);
        if (ft_strstr(line, "Plateau ") && !data.x)
            malloc_map(line, &data);
        if (ft_isdigit(line[0]) && !data.end)
            data.map[data.i++] = ft_strsub(line, 4, data.x);
        else if (data.end)
        {
            get_token(line, &data);
            data.end = ft_strstr(line, "<got ") ? 0 : 1;
            data.i = 0;
        }
        argc++;
		ft_strdel(&line);
	}
    find_the_spot(0, 0, &data);
    print_map(0, &data);
    return (0);
}

void	print_map(int j, t_fil *data)
{
	while (j < data->y)
	{
		printf("|%s|\n", data->map[j]);
		j++;
	}
}