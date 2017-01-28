/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:17:29 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/12 20:05:55 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fprime(unsigned int nb)
{
	unsigned	i;

	if (nb == 1)
		printf("1");
	else
	{
		i = 1;
		while (nb > 1)
		{
			if (nb % ++i == 0)
			{
				printf("%d", i);
				nb /= i;
				if (nb > 1)
					printf("*");
				--i;
			}
		}
	}
}


int		main(int ac, char **av)
{
	if (ac == 2 && *av[1])
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
