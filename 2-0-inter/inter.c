/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:41:12 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/07 17:43:03 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check(char *s1, int i)
{
	int a;

	a = 0;
	while (a < i)
	{
		if (s1[a] == s1[i])
			return (0);
		++a;
	}
	return (1);
}

void	inter(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (check(s1, i))
		{
			while (*s2)
			{
				if (s1[i] == *s2++)
				{
					write(1, s2 - 1, 1);
					break;
				}
			}
		}
		++i;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
