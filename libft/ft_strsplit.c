/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:25:07 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/21 15:55:46 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	null_prot_nbr_word(const char *s, char c)
{
	size_t	occurence;

	if (!s)
		return (0);
	if (!*s)
		return (0);
	occurence = 1;
	while (*++s)
		if (*s != c && *(s - 1) == c)
			occurence++;
	return (occurence);
}

static void		start_and_end(const char *s, char c, size_t *start, size_t *end)
{
	*start = *end;
	while (s[*start])
	{
		if (s[*start] == c)
			*start += 1;
		else
		{
			*end = *start;
			while (s[*end] != c)
				*end += 1;
			return ;
		}
	}
}

static char		*ft_strunchr(const char *s, int c)
{
	if (*s != c)
		return ((char*)s);
	while (*(s++))
		if (*s != c)
			return ((char*)s);
	return (0);
}

static char		**ft_desalloc(char ***p, size_t i)
{
	while (--i)
		free(*p[i]);
	free(*p[0]);
	free(*p);
	return (*p);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	len;
	size_t	se[2];
	size_t	i;
	char	**p;

	if (!s || !c)
		return (0);
	s = ft_strunchr(s, c);
	len = null_prot_nbr_word(s, c);
	if (!(p = (char**)malloc((len + 1) * sizeof(*p))))
		return (0);
	se[0] = 0;
	se[1] = 0;
	i = 0;
	while (i < len)
	{
		start_and_end(s, c, &se[0], &se[1]);
		if (!(p[i++] = ft_strsub(s, (unsigned int)se[0], se[1] - se[0])))
			return (ft_desalloc(&p, i));
	}
	p[i] = 0;
	return (p);
}
