/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:29:03 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/16 10:47:20 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if (!(buf = (char*)malloc(sizeof(*buf) * (i + 1))))
		return (0);
	i = 0;
	while (*s1)
		buf[i++] = *(s1++);
	buf[i] = '\0';
	return (buf);
}
