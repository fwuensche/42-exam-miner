/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:30:33 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/06 15:44:04 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//
#include <stdlib.h>//

int		max(int *tab, unsigned int len)
{
	int	max;

	max = (len) ? tab[len - 1] : 0;
	while (len--)
		if (tab[len] > max)
			max = tab[len];
	return (max);
}

int		main(void)//
{//
	int	*tab;//

	if (!(tab = (int*)malloc(sizeof(int) * 3)))//
		return (0);//
	tab[0] = 7;//
	tab[1] = 6;//
	tab[2] = 4;//
	printf("%d", max(tab, 3));//
	return (0);//
}//
