/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:01:38 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/15 10:01:53 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*sdst;
	char	*ssrc;

	sdst = (char*)dst;
	ssrc = (char*)src;
	while (n--)
	{
		*(sdst++) = *ssrc;
		if (*(ssrc++) == (char)c)
			return (sdst);
	}
	return (0);
}
