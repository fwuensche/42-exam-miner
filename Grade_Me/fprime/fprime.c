/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 04:18:19 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/24 04:20:48 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fprime(int nb, int a, int i)
{
	a++;
	while (nb % i && i < nb)
		++i;
	if (!nb % i)
	{
		if (a != 1)
			printf("*");
		printf("%d", i);
		if (nb != i)
			fprime(nb / i, a, i);
	}
	else
		printf("%d", nb);
}


int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]), 0, 2);
	printf("\n");
	return (0);
}
