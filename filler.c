/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:48:01 by eprusako          #+#    #+#             */
/*   Updated: 2020/11/25 17:32:39 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char    *filler(char **s)
{
    char *ss = "8 1";
    printf("%s", ss);
    return (ss);
}

int     main(int argc, char **argv) 
{
    char buffer[1000];
    int ret;

    
    
    
    ret = read(2, buffer, 1000);
    printf("LOOOOOL\n");
    printf("%s\n", buffer);
    printf("LOOOOOL\n");
    printf("buffer=%s\n", buffer);
    filler(argv);
    
}