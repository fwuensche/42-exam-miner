/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:36:30 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/28 18:24:40 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		len;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	len = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		++len;
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (len-- + sign)
	{
		s[len] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(len == 0) ? s[0] = '-' : 0;
	return (s);
}
