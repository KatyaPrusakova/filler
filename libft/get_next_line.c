/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:10:43 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/01 12:28:45 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function makes the line in to the line variable given to gnl. First it
** checks the save for a newline or end of file and takes the lenght for it.
** then we save it to line, make tmp from the rest of the save and free save.
*/

static int	makeline(char **line, char **save)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_strsub(*save, 0, len);
		tmp = ft_strdup(&((*save)[len + 1]));
		free(*save);
		*save = tmp;
		if ((*save)[0] == '\0')
			ft_strdel(save);
	}
	else
	{
		*line = ft_strdup(*save);
		ft_strdel(save);
	}
	return (1);
}

/*
** readline function checks if ret is smaller than 0 if it is it returns
** -1 since and error has occuerd. Then it checks if we have reached
** the end of the file and returns 0 if so. If none of the above happens
** it will go to makeline and return 1.
*/

static int	readline(const int fd, char **line, char **save, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && save[fd] == NULL)
		return (0);
	else
		return (makeline(line, &save[fd]));
}

/*
** get_next_line function reads from a file and returns the line ending in
** newline. It first of all checks if the file descriptor is valid then
** proceed to read from it. It then checks if the save is empty if it is
** memory will be allocated to it. Then it loops until a newline is found.
** then we return 1, 0 or -1 depending what we get from readline function.
*/

int			get_next_line(const int fd, char **line)
{
	static char	*save[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || fd > FD_MAX || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(save[fd], buf);
			free(save[fd]);
			save[fd] = tmp;
		}
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (readline(fd, line, save, ret));
}
