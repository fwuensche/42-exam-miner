/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 14:15:08 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/28 23:26:13 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putchar('a');
	else
	{
		while (*av[1])
			if (*av[1]++ == 'a')
			{
				ft_putchar('a');
				break;
			}
	}
	ft_putchar('\n');
	return (0);
}
