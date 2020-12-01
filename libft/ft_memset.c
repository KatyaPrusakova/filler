/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:10:06 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/15 16:39:28 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *ptr, int c, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)ptr;
	if (!ptr || len == 0)
		return (NULL);
	while (i < len)
	{
		dest[i++] = c;
	}
	return (ptr);
}
