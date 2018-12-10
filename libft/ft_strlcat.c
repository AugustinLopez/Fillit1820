/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:10:13 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 11:45:49 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (s2[j])
		j++;
	if (!s1 && !size)
		return (j);
	while (s1[i])
		i++;
	if (i > size)
		return (size + j);
	if (!size || !j)
		return (i + j);
	while (k < j && k + i + 1 < size)
	{
		s1[i + k] = s2[k];
		k++;
	}
	if (k <= j)
		s1[i + k] = '\0';
	return (i + j);
}
