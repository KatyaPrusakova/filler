/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/05 12:51:39 by eprusako         ###   ########.fr       */
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

int         is_valid(int i, int j, t_fil *data)
{
    if (i >= 0 && j >= 0 && i <= data->x && j <= data->y &&!ft_strchr(O, data->map[j][i]) && !ft_strchr(X, data->map[j][i]))
        return (1);
    return (0);
}


// int         ftft_valid(int i, int j, t_fil *data)
// {
//     if (i >= 0 && j >= 0 && i <= data->x && j <= data->y &&!ft_strchr(data->e, data->map[j][i]))
//         return (1);
// }
// from enemy plus one everytime its not end off map 
int          put_numbers(int i, int j, char r, t_fil *data)
{
//    printf("input is %c j %d  i %d\n", data->map[j][i], j, i);
    //if (ft_isdigit(data->map[j][i]))
    //    return (0);
    if (is_valid(i, j, data))
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

// int          ft_valid(int i, int j, int ii, int jj, t_fil *data)
// {
//     if ( ft_strchr(data->p, data->map[j - 1][i]) && data->t[jj -1 ][ii] != '*')
    
//         ftft_valid(i , j - 1, data) ||
//     ftft_valid(i + 1, j + 1, data) ||
//     ftft_valid(i, j + 1, data) ||
//     ftft_valid(i + 1, j, data) ||
//     ftft_valid(i - 1, j, data) ||
//     ftft_valid(i, j - 1,  data) ||
//     ftft_valid(i + 1, j - 1, data) ||
//     ftft_valid(i - 1, j + 1, data) )
//     {
//         return (1);
//     }
//     return (0);
// }

// int          put_token(int i, int j, t_fil *data)
// {
//  //   printf("input is %c\n", data->map[j][i]);
 
//     if (is_valid(i, j, data) && data->map[j][i] < data->min)
//     {
//         data->min = data->map[j][i];
//         return (1);
//     }
//     return (0);
// }

// int         full_put_token(t_fil *data)
// {
//     int j;
//     int i;

//     i = data->p_x;
//     j = data->p_y;
//     if (!data->p_y || !data->p_x)
//         return (0);
//     put_token(i - 1, j - 1, data);
//     put_token(i + 1, j + 1, data);
//     put_token(i, j + 1, data);
//     put_token(i + 1, j, data);
//     put_token(i - 1, j, data);
//     put_token(i, j - 1, data);
//     put_token(i + 1, j - 1, data);
//     put_token(i - 1, j + 1, data);
//         printf("here you shoud place the token %c \n", data->min);
//         //token_place(i, j, data);
//     return (0);
// }

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
    
    jj = 0;
    ii = 0;
    a = 0;
    fake_i = i;
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
            if (ft_strchr(data->p, data->map[j][i]) && data->t[jj][ii] == '*' && data->t[jj][ii+1] != '*')
            {
                data->answer_x = i;
                data->answer_y = j;
                a++;
            }
            // data->map[j][i] = data->t[jj][ii];
            i++;
            ii++;
        }
        j++;
        jj++;
    }
 //   print_map(0, data);
    if (a)
    {
        printf("this is answer %d %d \n", data->answer_y, data->answer_x);
        return (1);
    }
    return (0);
}

int        find_answer(int j, int i, t_fil *data)
{
    // int final_i;
    // int final_j;
    // i = data->p_x;
    // j = data->p_y;
    // i = data->p_x + data->t_x;
    // j = data->p_y + data->t_y;
    printf("find player %s\n", data->p);
    // if (is_valid(i, j, data->map[j][i], data))
    // {
    //     final_i = i;
    //     final_j = j;
    // }
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

int        find_on_map_player(int j, int i, t_fil *data)
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
   // full_put_token(&data);
    print_token(0, &data);
    find_answer(0, 0, &data);
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