/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcomlan <gcomlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:53:59 by angavrel          #+#    #+#             */
/*   Updated: 2022/08/13 17:26:04 by gcomlan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

/*
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (begin_list == NULL || *begin_list == NULL)
		return ;

	current = *begin_list;
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	current = *begin_list;
	ft_list_remove_if(&current->next, data_ref, cmp);
}
*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(curr);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		curr = curr->next;
	}
}

/*
// hey you, would you mind submitting a main for this exercise?
// yes.

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while ((s1[idx] == s2[idx]) && (s1[idx] != '\0' && s2[idx] != '\0'))
		idx++;
	return (s1[idx] - s2[idx]);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

t_list	*new(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*test_list;
	t_list	**begin_list;

	begin_list = &test_list;
	test_list = new("Follow the ");
	test_list->next = new("White rabbit...");
	test_list->next->next = new("!");
	test_list->next->next->next = new("!");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
	ft_list_remove_if(begin_list, "!", ft_strcmp);
	ft_putstr("Removing the dot -> (!)\n");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
}
*/
