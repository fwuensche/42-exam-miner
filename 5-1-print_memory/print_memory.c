/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:56:20 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/21 14:54:06 by angavrel         ###   ########.fr       */
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

void	ft_print_hex(int n, int i)
{
	if (i < 16)
		ft_putchar('0');
	if (n >= 16)
		ft_print_hex(n / 16, i);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	ft_putchar(n);
}

void	print_chars(unsigned char *t, size_t n)
{
	while (n--)
	{
		(*t > 31 && *t < 127) ? ft_putchar(*t) : ft_putchar('.');
		++t;
	}
	ft_putchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*t;
	size_t			i;
	int				column;
	int				row;

	t = (unsigned char *)addr;
	column = 1;
	row = 0;
	i = 0;
	while (size--)
	{
		t[i] == 0 ? ft_putstr("00") : ft_print_hex(t[i], t[i]);
		if (i > 0 && i % 2 == 1)
			ft_putchar(' ');
		if (column++ == 16)
		{
			print_chars(t + (row * 16), 16);
			column = 1;
			row++;
		}
		i++;
	}
	if ((column = i - (row * 16)) > 0)
	{
		i = column;
		while (i++ < 16)
			(i % 2 == 1) ? ft_putchar(' ') : ft_putstr("    ");
		print_chars(t + (row * 16), column);
	}
}
