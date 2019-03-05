/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensche <fwuensche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 08:09:54 by fwuensche         #+#    #+#             */
/*   Updated: 2019/03/05 08:10:19 by fwuensche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		count_words(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char *word;
	int i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int word_count;
	char **arr;
	int i;

	word_count = count_words(str);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			arr[i] = malloc_word(str);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>

// int		main(int ac, char **av)
// {
// 	char **arr;

// 	char *phrase = "Hello, Flavio!";
// 	arr = ft_split(phrase);
// 	printf("%s\n", arr[0]);
// 	printf("%s\n", arr[1]);
// 	printf("%s\n", arr[2]);
// }
