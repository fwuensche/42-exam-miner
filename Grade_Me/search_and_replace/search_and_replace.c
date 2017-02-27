/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 06:33:21 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/27 18:13:06 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char	*search_and_replace(char *s, char a, char b)
{
	int	i = -1;

	while (s[++i])
		(s[i] == a) ? s[i] = b : 0;
	return (s);
}

int		main(int ac, char **av)
{
	if (ac == 4 && *av[2] && !av[2][1] && *av[3] && !av[3][1])
		ft_putstr(search_and_replace(av[1], *av[2], *av[3]));
	write(1, "\n", 1);
	return (0);
}
