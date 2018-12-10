/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:20:58 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 12:08:21 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*p;
	char	*buf;

	if (size > 9223372036854775807)
		return (0);
	if (!(p = (void*)malloc(size)))
		return (0);
	buf = (char*)p;
	while (size--)
		*(buf++) = 0;
	return (p);
}
