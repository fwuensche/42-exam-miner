/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:43:06 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/27 11:29:47 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*p;
	t_list	*t;

	t = lst;
	while (lst)
	{
		p = lst->next;
		while (p)
		{
			if (!(*cmp)(lst->data, p->data))
				swap(&lst->data, &p->data);
			p = p->next;
		}
		lst = lst->next;
	}
	return (t);
}
