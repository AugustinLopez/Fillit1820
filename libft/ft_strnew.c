/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:24:54 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 12:08:41 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;

	if (size >= 9223372036854775807)
		return (0);
	if (!(p = (char*)malloc((size + 1) * sizeof(*p))))
		return (0);
	ft_bzero(p, size + 1);
	return (p);
}
