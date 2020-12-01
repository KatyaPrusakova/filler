/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/10/15 16:37:00 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(uintmax_t n, int base)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static	int		ft_minus(uintmax_t num, int base, int sign)
{
	if (base != 10)
		return (0);
	sign = (num < 0 ? 1 : 0);
	num = (sign ? -num : num);
	return (sign);
}

char			*ft_itoa_base(uintmax_t num, int base, int change)
{
	char		*str;
	char		*format;
	int			len;
	int			sign;

	if (base < 2 && base > 16)
		return (0);
	sign = ft_minus(num, base, change);
	format = (change > 0) ? "0123456789ABCDEF" : "0123456789abcdef";
	len = ft_len(num, base);
	if (!(str = ft_strnew(len)))
		return (0);
	while (len)
	{
		len--;
		str[len] = format[num % base];
		num = num / base;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
