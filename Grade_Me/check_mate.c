/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:08:36 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/27 21:17:31 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** full stack solution
*/

#include <unistd.h>
#include <stdio.h>
int		solve(int len, char m[len][len], int a, int b)
{
	int		i;

	if (m[b + 1][a + 1] == 'P' || m[b + 1][a - 1] == 'P')
		return (0);
	i = 0;
	while (i < len)
	{
		if (m[b][i] == 'Q' || m[i][a] == 'Q' || m[b][i] == 'R' || m[i][a] == 'R')
		{
			printf("baba");
			return (0);
		}
		if (i < b)
		{
			if (i < a && (m[b - i - 1][a - i - 1] == 'B' || m[b - i - 1][a - i - 1] == 'Q'))
				return (0);
			if (a + i < len && (m[b - i - 1][a + i + 1] == 'B' || m[b - i - 1][a + i + 1] == 'Q'))
				return (0);
		}
		if (b + i < len)
		{
			if (i < a && (m[b + i + 1] [a - i - 1] == 'B' || m[b + i + 1] [a - i - 1] == 'Q'))
				return (0);
			if (a + i < len && (m[b + i + 1] [a + i + 1] == 'B' || m[b + i + 1] [a + i + 1] == 'Q' ))
				return (0);
		}
		i++;
	}
	return (1);
}

int		check_mate(const int y, char **av)
{
	char	m[y - 1][y - 1];
	int		b = 0;
	int		a = 0;
	int		i = 0;
	int		j = 0;

	while (j < y)
	{
		i = 0;
		while (av[j + 1][i])
		{
			m[j][i] = av[j + 1][i];
			if (m[j][i] == 'K')
			{
				a = i;
				b = j;
			}
			++i;
		}
		m[j][i] = 0;
		++j;
	}
	return (!(solve(y, m, a, b)) ? 0 : 1);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		(check_mate(ac - 1, av)) ? write(1, "Fail", 4) : write(1, "Success", 7);
	write(1, "\n", 1);
	return (0);
}
