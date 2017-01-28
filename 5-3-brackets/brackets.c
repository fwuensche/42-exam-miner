/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:31:57 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/27 12:57:53 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		isclosing(char c)
{
	if (c == 125)
		return (3);
	else if (c == 93)
		return (2);
	else if (c == 41)
		return (1);
	return (0);
}

int		isopening(char c)
{
	if (c == 123)
		return (3);
	else if (c == 91)
		return (2);
	else if (c == 40)
		return (1);
	return (0);
}

static int		is_matching_bracket(char a, char b)
{
	return ((a == '(' && b == ')') ||
			(a == '{' && b == '}') ||
			(a == '[' && b == ']'));

}
char	*find_match(char b, char *s, int i)
{
	while (i >= 0)
	{
		if (is_matching_bracket(s[i], b))
			return (s + i);
		if (isopening(s[i]) && !is_matching_bracket(s[i], b))
			return (NULL);
		i--;
	}
	return (NULL);
}

int		brackets(char *s)
{
	int		i;
	int		a;
	char	*b;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (isclosing(s[i]))
		{
			a = isclosing(s[i]);
			if ((b = find_match(s[i], s, i)))
			{
				s[i] = '.';
				*b = '.';
				i = -1;
			}
			else
				return (0);
		}
		i++;
	}
	i = -1;
	while (s[++i])
		if (isopening(s[i] || isclosing(s[i])))
		{
			write(1, "Error", 5);
			return (0);
		}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
		(brackets(av[i])) ? write(1, "OK", 2) : write(1, "Error", 5);
	write (1, "\n", 1);
	return (0);
}
