/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/30 09:35:09 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int ch)
{
	size_t		i;
	char		*new;

	i = 0;
	new = (char*)s;
	while (new[i] != '\0')
	{
		if (new[i] == ch)
			return (&new[i]);
		i++;
	}
	if (new[i] == '\0' && !ch)
		return (&new[i]);
	return (0);
}
