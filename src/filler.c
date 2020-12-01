/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/01 14:28:55 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char    *filler(char **s)
{
    char *ss = "8 1";
   if (s[0] == ss)
        return (ss);
    printf("THIS IS FILLER\n  %s", ss);
    return (ss);
}

int          main(int argc, char **argv) 
{
    t_fil   data;
    char    *line;
    
    line = NULL;
    ft_bzero(&data, sizeof(t_fil));
    argc = 0;
    while (get_next_line(0, &line) > 0)
	{
        printf("%d|| %s ||\n", argc, line);
        argc++;
		ft_strdel(&line);
	}
    filler(argv);
}