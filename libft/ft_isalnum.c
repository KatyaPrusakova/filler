/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:10:06 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/30 09:33:44 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int a)
{
	if (a >= 65 && a <= 90)
		return (1);
	if (a >= 97 && a <= 122)
		return (1);
	if (a >= 48 && a <= 57)
		return (1);
	else
		return (0);
}