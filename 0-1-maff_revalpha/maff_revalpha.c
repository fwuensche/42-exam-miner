/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:07:00 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/05 19:17:30 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	int i;

	i = 123;
	while (i-- > 97)
		(i % 2 == 0) ? ft_putchar(i) : ft_putchar(i - 32);
	ft_putchar('\n');;
	return (0);
}
