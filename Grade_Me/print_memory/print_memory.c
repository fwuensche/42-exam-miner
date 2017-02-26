/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 04:29:55 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/24 05:29:18 by angavrel         ###   ########.fr       */
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

void	ft_puthex(int n)
{
	if (n / 16)
		ft_puthex(n / 16);
	ft_putchar(n % 16 + (n % 16 < 10 ? '0' : 'a' - 10));
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
	int				i;
	int				col;
	int				row;

	t = (unsigned char *) addr;
	col = 1;
	row = 0;
	i = 0;
	while (size--)
	{
		if (t[i] <  16)
			ft_putchar('0');
		ft_puthex(t[i]);
		if (i & 1)
			ft_putchar(' ');
		if (col++ >> 4)
		{
			print_chars(t + (row * 16), 16);
			col = 1;
			row++;
		}
		i++;
	}
	if ((col = i - (row * 16)) > 0)
	{
		i = col;
		while (i++ < 16)
			(i & 1) ? ft_putchar(' ') : ft_putstr("    ");
		print_chars(t + (row * 16), col);
	}
}
