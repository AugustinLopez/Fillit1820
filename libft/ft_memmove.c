/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:33:47 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 10:49:11 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	cdst = (char*)dst;
	csrc = (char*)src;
	if (cdst < csrc)
		while (len--)
			*(cdst++) = *(csrc++);
	else if (cdst > csrc)
		while (len--)
			cdst[len] = csrc[len];
	return (dst);
}
