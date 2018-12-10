/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:26 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 12:10:57 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_strlen(const char *s)
{
	size_t	len;
	size_t	offset;

	len = 0;
	offset = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
			++offset;
		else
			offset = 0;
		++s;
		++len;
	}
	return (len - offset);
}

char			*ft_strtrim(char const *s)
{
	char	*p;
	char	*buf;
	size_t	len;

	if (!s)
		return (0);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	len = trim_strlen(s);
	if (!(p = ft_strnew(len)))
		return (0);
	buf = p;
	while (len--)
		*(buf++) = *(s++);
	*buf = '\0';
	return (p);
}
