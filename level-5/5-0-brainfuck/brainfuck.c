/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:40:26 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/24 21:46:46 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	brainfuck(char *str)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * 2048);
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			*ptr++;
		else if (*str == '-')
			*ptr--;
		else if (*str == '[' && !*ptr)
			while (*str != ']')
				*str++;
		else if (*str == ']' && !*ptr)
			while (*str != '[')
				*str--;
		else if (*str == '.')
			write(1, ptr, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		brainfuck(argv[1]);
	write(1, "\n", 1);
}
