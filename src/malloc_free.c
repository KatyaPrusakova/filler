/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/11 21:35:54 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		malloc_token(int fd, char *line, t_fil *data)
{
	int		i;
	int		j;

	i = 0;
	get_coord(&data->t_x, &data->t_y, line);
	if (!(data->t = (char**)ft_memalloc(sizeof(char*) * data->t_y + 1)))
		puterror(0);
	while (i < data->t_y)
		data->t[i++] = (char*)ft_memalloc(sizeof(char) * data->t_x + 1);
	i = 0;
	j = 0;
	while (i++ < data->t_y)
	{
		get_next_line(fd, &line);
		ft_strcpy(data->t[j], line);
		j++;
		ft_strdel(&line);
	}
	create_map(0, 0, data);
}

void		malloc_map(int fd, char *line, t_fil *data)
{
	int		i;

	i = 0;
	get_coord(&data->x, &data->y, line);
	if (!(data->map = (int**)ft_memalloc(sizeof(int*) * data->y)))
		puterror(0);
	while (i < data->y)
		data->map[i++] = (int*)ft_memalloc(sizeof(int) * data->x);
	i = 0;
	get_next_line(fd, &line);
	ft_strdel(&line);
	while (i < data->y)
	{
		get_next_line(fd, &line);
		copy_map(ft_strsub(line, 4, data->x), i, data);
		i++;
		free(line);
	}
}

void		copy_map(char *line, int y, t_fil *data)
{
	int		x;

	x = 0;
	while (x < data->x)
	{
		if (line[x] == '.')
			data->map[y][x] = 0;
		else if (ft_strchr(data->e, line[x]))
			data->map[y][x] = -2;
		else if (ft_strchr(data->p, line[x]))
			data->map[y][x] = -1;
		x++;
	}
}

void		free_map(t_fil *data)
{
	int		i;

	i = 0;
	if (data->map)
	{
		while (i < data->y)
		{
			free(data->map[i++]);
		}
		free(data->map);
		data->map = NULL;
	}
	ft_memdel((void **)&data->map);
}

void		free_piece(t_fil *data)
{
	int		i;
	char	*str;

	if (!data->t)
		return ;
	i = 0;
	while (i < data->t_y)
	{
		str = data->t[i];
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&data->t);
}
