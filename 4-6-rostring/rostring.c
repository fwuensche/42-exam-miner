/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:43:17 by angavrel          #+#    #+#             */
/*   Updated: 2016/12/05 18:57:55 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		r_size(char *s)
{
	unsigned int n;
	unsigned int i;

	n = 0;
	i = 0;
	while (s[i])
		if (!ft_isblank(s[i++]) && (n == 0 || ft_isblank(s[i - 2])))
			++n;
	return (n);
}

char	**ft_strsplit(char *s)
{
	int		i = 0;
	int		j = 0;
	int		k;
	char	**r;
	int		w_len = 0;

	if (!(r = (char **)malloc(sizeof(char *) * (r_size(s) + 1))))
		return (0);
	while (s[i] && j < r_size(s))
	{
		while (s[i] && ft_isblank(s[i]))
			i++;
		while (s[i] && !ft_isblank(s[i]))
		{
			w_len++;
			i++;
		}
		if (!(r[j] = (char *)malloc(sizeof(char) * (w_len + 1))))
			return (0);
		k = 0;
		while (w_len)
			r[j][k++] = s[i - w_len--];
		r[j++][k] = '\0';
	}
	free(r);
	return (r);
}

void	rostring(char *s)
{
	char	**r = ft_strsplit(s);
	int		n = r_size(s);
	int		i = 0;
	char	*temp = r[0];

	if (n > 0)
	{
		while (i < n - 1)
		{
			r[i] = r[i + 1];
			i++;
		}
		r[n - 1] = temp;
		i = 0;
		while (n-- > 1)
		{
			ft_putstr(r[i++]);
			ft_putstr(" ");
		}
		ft_putstr(r[i]);
	}
	r = NULL;
}

int		main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
