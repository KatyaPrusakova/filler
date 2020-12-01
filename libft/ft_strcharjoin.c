/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/01 12:28:20 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcharjoin(int c, const char *s)
{
	size_t			len;
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	len = (2 + ft_strlen(s));
	str = (char *)ft_memalloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	j = 1;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free((void *)s);
	return (str);
}
