/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:16:51 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/28 18:03:42 by angavrel         ###   ########.fr       */
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

/* need to fix :
 = Test 5 ===================================================
 $> ./2qkx0msujfxnki0oj0ta6f75 "LOyB" "XUlnh9yE1LRpvfrTb"
 $> diff -U 3 user_output_test5 test5.output | cat -e
 --- user_output_test52017-01-28 17:58:58.0000	00000 +0100$
 +++ test5.output2017-01-28 17:58:58.000000000 +0100$
 @@ -	1 +1 @@$
 -L$
 +Ly$
 */
