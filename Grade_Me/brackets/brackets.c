/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:18:53 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/27 13:18:58 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		bracketsclose(char *s, char c, int b, int i)
{
	while (b && *(++s) && i++)
		if (*s == c || *s == c + c % 2 + 1)
			*s == c ? ++b : --b;
	return (i);
}

int		brackets(char *s, char c)
{
	if (*s == c)
		return (1);
	else if (!*s || *s == ')' || *s == '}' || *s == ']')
		return (0);
	else if (*s == '(' || *s == '{' || *s =='[')
		return (brackets(s + 1, *s + *s % 2 + 1)
				* brackets(s + bracketsclose(s, *s, 1, 1), c));
	else
		return (brackets(s + 1, c));
}

int		main(int ac, char **av)
{
	int i = 0;

	if (ac > 1)
		while (++i < ac)
			brackets(av[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	else
		write(1, "\n", 1);
	return (0);
}
