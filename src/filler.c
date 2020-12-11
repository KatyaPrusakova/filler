/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/11 19:39:26 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_player(char *line, t_fil *data)
{
	if (ft_strstr(line, "$$$ exec "))
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

int				main(void)
{
	t_fil		data;
	char		*line;
	int			fd;

	fd = 0;
	line = NULL;
	ft_bzero(&data, sizeof(t_fil));
	while (get_next_line(fd, &line) && !ft_strstr(line, "$$$ exec "))
		ft_strdel(&line);
	find_player(line, &data);
	play_game(fd, line, &data);
}

void			print_res(t_fil *data)
{
	ft_putnbr(data->min_y);
	ft_putchar(' ');
	ft_putnbr(data->min_x);
	ft_putchar('\n');
}

int				puterror(int i)
{
	if (i == 0)
		exit(0);
	return (0);
}
