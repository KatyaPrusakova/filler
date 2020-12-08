/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/08 19:35:13 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void        malloc_token(char *line, t_fil *data)
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

void        malloc_map(char *line, t_fil *data)
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