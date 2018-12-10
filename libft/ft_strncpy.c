/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:02:50 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 11:23:41 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *buf;

	if (!len)
		return (dst);
	buf = dst;
	len++;
	while (*src && --len)
		*(dst++) = *(src++);
	if (len--)
		while (len--)
			if (*dst)
				*(dst++) = '\0';
	return (buf);
}
