/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:26:55 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/21 11:27:58 by angavrel         ###   ########.fr       */
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

	i = 96;
	while (i++ < 122)
		(i % 2 == 0) ? ft_putchar(i - 32) : ft_putchar(i);
	ft_putchar('\n');
	return (0);
}
