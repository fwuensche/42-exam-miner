/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:36:55 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/26 17:43:56 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		isb(char c)
{
	return ((c == ' ' || c == '\t') ? 1 : 0);
}

void	epur_str(char *s)
{
	int start;
	int len = 0;
	int i = 0;

	while (s[i])
		if (!isb(s[i++])))
			++len;
	start = 0;
	while (*s)
	{
		while (isb(*s) && (!isb(*(s + 1)) || !start))
			++s;
		start = 1;
		while (*s && !isb(*s))
		{
			write(1, s, 1);
			len--;
			++s;
		}
		if (len)
			write(1, " ", 1);
		while (isb(*s))
			++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
}
