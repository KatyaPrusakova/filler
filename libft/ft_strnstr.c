/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/30 09:49:22 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	while (big[i] != '\0' && (size_t)i < n)
	{
		while (big[i + j] == little[j])
		{
			if ((j == len - 1) && ((size_t)(i + j) < n))
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
