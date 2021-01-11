/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoufi <musoufi@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:28:43 by fwuensch          #+#    #+#             */
/*   Updated: 2021/01/11 14:48:46 by musoufi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void solve(char *str1, char *str2) {
    int i;
    int ascii[256] = {0};

    i = 0;
    while (str2[i])
    {
        if (ascii[(int)str2[i]] == 0)
            ascii[(int)str2[i]] = 1;
        i++;
    }

    i = 0;
    while (str1[i])
    {
        if (ascii[(int)str1[i]] == 1)
        {
            ascii[(int)str1[i]] = 2;
            write(1, &str1[i], 1);
        }
        i++;
    }

}

int	main(int argc, char **argv) {
	if (argc == 3)
		solve(argv[1], argv[2]);
	write(1, "\n", 1);
	return 0;
}
