/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:45 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 10:49:14 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Perform as well as memset when compiled with -O3.
*/

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*buf;

	buf = (char*)b;
	while (len--)
		*(buf++) = (char)c;
	return (b);
}
