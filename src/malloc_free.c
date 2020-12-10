/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/10 16:01:23 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int         puterror(int i)
{
    if (i == 0)
        exit (0);
    return (0);
}

/*
** Parsing the token
*/

extern int g_fd;

void        malloc_token(int fd, char *line, t_fil *data)
{
    int     i;
	int		tmp;

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
    i = 0;
	tmp = data->t_y;
	dprintf(g_fd, "%d\n", data->t_y);
    while (tmp--)
    {
		get_next_line(fd, &line);
		
		dprintf(g_fd, "%s\n", line);
        while (data->raz < data->t_y)
        {
            ft_strcpy(data->t[data->raz], line);
            data->raz++;
        }
        ft_strdel(&line);
    }
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
