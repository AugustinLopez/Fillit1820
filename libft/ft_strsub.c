/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:18 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/19 09:28:13 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*p;
	char		*buf;

	if (!s)
		return (0);
	if (!(p = ft_strnew(len)))
		return (0);
	buf = p;
	s = s + start;
	while (len--)
		if (*s)
			*(p++) = *(s++);
	*p = '\0';
	return (buf);
}
