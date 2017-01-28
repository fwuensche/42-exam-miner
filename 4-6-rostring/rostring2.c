/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostrin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:33:32 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/05 18:57:37 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while	(*s)
		write(1, s++, 1);
}

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		rostring(char *s)
{
	int		i = -1;
	char	*r;
	int		w_len = 0;

	while (*s)
	{
		while (ft_isblank(*s))
			s++;
		if (*s && !ft_isblank(*s))
		{
			if (!w_len)
			{
				while (*s && !ft_isblank(*s++))
					w_len++;
				if (!(r = (char *)malloc(sizeof(char) * (w_len + 1))))
					return (0);
				while (++i < w_len)
					r[i] = *(s - w_len + i - 1);
				r[i] = '\0';
			}
			else
			{
				while (*s && !ft_isblank(*s) && write(1, s++, 1));
				write(1, " ", 1);
			}
		}
	}
	ft_putstr(r);
	free(r);
	r = NULL;
	return (1);
}

int		main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
