/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:44:16 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/15 12:49:04 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n++)
		return (0);
	while (--n && *s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	if (!n && *(--s1) == *(--s2))
		return (0);
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
