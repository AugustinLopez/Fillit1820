/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:20:32 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 12:11:42 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			len;
	int				buf;
	unsigned int	positif;
	char			*p;

	len = (n < 0) + 1;
	buf = n;
	while ((buf /= 10))
		++len;
	if (!(p = ft_strnew(len)))
		return (0);
	if (n < 0)
	{
		p[0] = '-';
		buf = 1;
	}
	positif = n * (1 - 2 * (n < 0));
	while (len-- > (unsigned int)buf)
	{
		p[len] = '0' + positif % 10;
		positif /= 10;
	}
	return (p);
}
