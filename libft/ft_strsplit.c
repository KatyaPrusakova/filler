/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/30 10:38:39 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_countwords(const char *s, char c)
{
	int				i;
	int				n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
		}
		n++;
	}
	return (n);
}

static char			*ft_ftstrndup(const char *s1, size_t n)
{
	size_t			i;
	char			*new;

	i = 0;
	new = (char *)malloc(sizeof(*new) * (n + 1));
	if (!new)
		return (0);
	while (i < n)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t			w;
	char			**new;

	i = 0;
	w = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			new[w] = ft_ftstrndup(s + j, i - j);
			w++;
		}
	}
	new[w] = NULL;
	return (new);
}
