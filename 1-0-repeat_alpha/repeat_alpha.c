/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:23:34 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/05 19:30:36 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}


int		letter_count(char c)
{
	int	repeat;

	if (c >= 'A' && c <= 'Z')
		repeat = c - 64;
	else if (c >= 'a' && c <= 'z')
		repeat = c - 96;
	else
		repeat = 1;
	return (repeat);
}



int		main(int ac, char **av)
{
	int	repeat;

	if (ac == 2)
	{
		while (*av[1])
		{
			repeat = letter_count(*av[1]);
			while (repeat--)
				ft_putchar(*av[1]);
			av[1]++;
		}
	}
	ft_putchar('\n');
}
