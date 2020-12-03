/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/03 21:28:38 by eprusako         ###   ########.fr       */
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
int          put_numbers(int i, int j, char r, t_fil *data)
{
//    printf("input is %c j %d  i %d\n", data->map[j][i], j, i);
    //if (ft_isdigit(data->map[j][i]))
    //    return (0);
    if (is_valid(i, j, data->map[j][i], data))
    {
        data->map[j][i] = r;
        //solve_it(i, j, r, data);
        return (1);
    }
    return (0);
}

int          fill_it(int i, int j, char r, t_fil *data)
{
    if (put_numbers(i, j, r, data))
    {
        return (1);
    } 
    // while (temp2 < data->y)
    // {
    //     if (put_numbers(temp, temp2, data))
    //     {
    //         data->i++;
    //     }
    //     temp2++;
    // }
    // data->i = 0;
    // temp = i;
    // temp2 = j;
    // while (temp2 < data->y && temp < data->x)
    // {
    //     if (put_numbers(temp, temp2, data))
    //     {
    //         data->i++;
    //     }
    //         temp++;
    //         temp2++;
    // }
//     temp = i - 1;
//     temp2 = j - 1;
//     while (temp2 >= 0 && temp >= 0)
//     {
//         if (is_valid(temp, temp2, data->map[temp2][temp], data))
//         {
//             data->map[temp2][temp] = data->i + '0';
//             solve_it(temp, temp2, data->i, data);
//         }
//         temp--;
//         temp2--;
//     }
//     temp = j + 1;
//     while (temp < data->y)
//     {
//         if (is_valid(i, temp, data->map[temp][i], data))
//         {
//             data->map[temp][i] = temp + '0';
//         }
//         temp++;
//     }
//     temp = i + 1;
//     temp2 = j - 1;
//     while (temp < data->x && temp2 >= 0)
//     {
//         if (is_valid(temp, temp2, data->map[temp2][temp], data))
//         {
//             data->map[temp2][temp] = temp + '0';
//         }
//         temp++;
//         temp2--;
//     }
//     temp = i - 1;
//     temp2 = j + 1;
//     while (temp2 < data->x && temp >= 0)
//     {
//         if (is_valid(temp, temp2, data->map[temp2][temp], data))
//         {
//             data->map[temp2][temp] = temp + '0';
//         }
//         temp--;
//         temp2++;
//     }
//     return (0);
return (0);
}

void         solve_it(int i, int j, char fill, t_fil *data)
{
    while (j < data->y)
    {
        i++;
        while (i < data->x)
        {
            if (is_valid(i, j, data->map[j][i], data))
            {
                data->map[j][i] = fill;
                fill++;
            }
            i++;
        }
        j++;
    }
}

int          put_token(int i, int j, t_fil *data)
{
 //   printf("input is %c\n", data->map[j][i]);
    if (is_valid(i, j, data->map[j][i], data) && data->map[j][i] < data->min)
    {
        data->min = data->map[j][i];
        return (1);
    }
    return (0);
}

int         full_put_token(t_fil *data)
{
    int j;
    int i;

    i = data->p_x;
    j = data->p_y;
    if (!data->p_y || !data->p_x)
        return (0);
    put_token(i - 1, j - 1, data);
    put_token(i + 1, j + 1, data); // ||
    put_token(i, j + 1, data);
    put_token(i + 1, j, data);
    put_token(i - 1, j, data);
    put_token(i, j - 1, data);
    put_token(i + 1, j - 1, data);
    put_token(i - 1, j + 1, data);
        printf("here you shoud place the token %c \n", data->min);
        //token_place(i, j, data);
    return (0);
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

int        find_on_map_player(int j, int i, t_fil *data)
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
                 
                full_fill_it(data->e_x, data->e_y, data->i + '0', data);
                
                // fill_it(i - 1, j, data);
                //data->i = 0;
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

int          main(int argc, char **argv) 
{
    t_fil   data;
    char    *line;
    int     fd;
    
    line = NULL;
    ft_bzero(&data, sizeof(t_fil));
    argc = 0;
    data.min = (char)127;
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
    find_on_map_player(0, 0, &data);
    print_map(0, &data);
    full_put_token(&data);
    print_token(0, &data);
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

void	print_token(int j, t_fil *data)
{
    printf("|token print|\n");
	while (j < data->t_y)
	{
		printf("|%s|\n", data->t[j]);
		j++;
	}
}