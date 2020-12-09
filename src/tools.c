/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:52:16 by eprusako          #+#    #+#             */
/*   Updated: 2020/12/09 11:05:56 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int         is_valid(int i, int j, t_fil *data)
{
    if (i >= 0 && j >= 0 && i <= data->x && j <= data->y &&!ft_strchr(O, data->map[j][i]) && !ft_strchr(X, data->map[j][i]))
        return (1);
    return (0);
}

// int         full_fill_it(int i, int j, char r, t_fil *data)
// {
//     int tj;
//     int ti;
//     char c;

    
//     tj = j;
//     ti = i;
//     j = tj;
//     i = ti;
//     c = r;
//     while (i < data->x)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         i++;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (j < data->y)
//     {
//         if(fill_it(i, j, r, data))
//             r++;
//         j++;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (i < data->x && j < data->y)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         i++;
//         j++;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (i >= 0 && j >= 0)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         i--;
//         j--;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (i >= 0)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         i--;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (j >= 0)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         j--;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (i < data->x && j >= 0)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         i++;
//         j--;
//     }
//     j = tj;
//     i = ti;
//     r = c;
//     while (j < data->y && i >= 0)
//     {
//         if (fill_it(i, j, r, data))
//            r++;
//         j++;
//         i--;
//     }
//     return (0);
// }
