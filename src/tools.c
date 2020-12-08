/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:52:16 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/08 19:39:07 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int         is_valid(int i, int j, t_fil *data)
{
    if (i >= 0 && j >= 0 && i <= data->x && j <= data->y &&!ft_strchr(O, data->map[j][i]) && !ft_strchr(X, data->map[j][i]))
        return (1);
    return (0);
}
