/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:56:32 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/27 12:56:11 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_printhex(int n)
{
	int c;

	if (n >= 16)
		ft_printhex(n / 16);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	ft_putchar(c);
}

void	ft_printchars(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *t = (unsigned char *)addr;
	size_t		i = 0;
	int			col;
	int			row = 0;
	size_t		tmp = 0;

	while (i < size)
	{
		col = -1;
		if ((size - i) < 16)
			tmp = 4 - (size - i) / 4;
		while (i < size && ++col < 16)
		{
			if (t[i] < 16)
				ft_putchar('0');
			ft_printhex(t[i]);
			if (i++ % 2)
				ft_putchar(' ');
		}
		if (tmp)
			while (tmp--)
				ft_putstr("          ");
		i = 16 * row;
		col = -1;
		while (i < size && ++col < 16)
			ft_printchars(t[i++]);
		ft_putchar('\n');
		++row;
		i = 16 * row;
	}
}
