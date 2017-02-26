/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:10:13 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/26 16:29:01 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	char	*back;
	char	*front;
	char	tmp;

	front = str;
	back = str;
	while (*back)
		++back;
	--back;
	while (*front < *back)
	{
		tmp = *front;
		*front++ = *back;
		*back-- = tmp;
	}
	return (str);
}
