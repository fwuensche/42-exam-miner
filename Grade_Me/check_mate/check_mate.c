/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:31:47 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/02 18:44:19 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_diag(int len, char b[len][len])
{

}

int	check_mate(int len, char b[len][len])
{
	int		n;
	int		y;
	int		x;
	int		a;
	int		b;

	a = 0;
	b = 0;
	y = -1;
	while (++y < len)
	{
		x = -1;
		while (++x < len)
		{
			if (b[y][x] == 'K')
			{
				a = x;
				b = y;
			}
		}
	}
	n = 0;
	n += check_diag(len, b);
	n += check_row_col(len, b);
	n += check_pawn(len, b);
	return (n);
}

int	board(int len, char **av)
{
	char	b[len][len];
	int		i;
	
	i = -1;
	while (i < len)
		*b[i] = *av[i + 1];
	return (check_mate(len, b));
}

int		main(int ac, char **av)
{
	if (ac > 1)
		(parse(ac - 1, av)) ? write(1, "Success", 7) : write(1, "Fail", 4);
	write(1, "\n", 1);
	return (0);
}
