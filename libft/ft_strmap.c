/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:24:29 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/21 15:39:31 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*p;
	char	*buf;

	if (!s || !f)
		return (0);
	len = ft_strlen((char*)s);
	if (!(p = ft_strnew(len)))
		return (0);
	buf = p;
	while (len--)
		*(buf++) = f(*(char*)s++);
	return (p);
}
