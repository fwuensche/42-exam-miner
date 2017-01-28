/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:16:51 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/08 16:37:08 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check(char *s, int i, char c)
{
	int a;

	a = -1;
	while (++a < i)
		if (s[a] == c)
			return (0);
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int j;

	i = -1;
	while (s1[++i])
		if (check(s1, i, s1[i]))
			write(1, &s1[i], 1);
	j = -1;
	while (s2[++j])
		if (check(s1, i, s2[j]) && check(s2, j, s2[j]))
			write(1, &s2[j], 1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
