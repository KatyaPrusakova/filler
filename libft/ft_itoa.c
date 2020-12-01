/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/26 16:19:02 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(int n, int sign)
{
	int			len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	len = len + (sign ? 1 : 0);
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			sign;
	int			len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0 ? 1 : 0);
	n = (sign ? -n : n);
	len = ft_len(n, sign);
	if (!(str = ft_strnew(len)))
		return (0);
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
