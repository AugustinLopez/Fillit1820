/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:46:54 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 12:12:04 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** https://www.utf8-chartable.de/unicode-utf8-table.pl
*/

void	ft_putchar_fd(char c, int fd)
{
	int		i[2];

	if (c >= 0)
		write(fd, &c, 1);
	else if (c < 0)
	{
		i[1] = 0xFF + 1 + c;
		if (i[1] < 0xC0)
			i[0] = 0xC2;
		else
		{
			i[1] -= 0x40;
			i[0] = 0xC3;
		}
		write(fd, &i[0], 1);
		write(fd, &i[1], 1);
	}
}
