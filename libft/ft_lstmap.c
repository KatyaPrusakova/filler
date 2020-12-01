/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 11:13:58 by eprusako          #+#    #+#             */
/*   Updated: 2020/06/26 16:21:28 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*current;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = (*f)(lst);
	current = head;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (!(current = current->next))
			return (NULL);
		current = current->next;
	}
	return (head);
}
