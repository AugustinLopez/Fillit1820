/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/19 15:54:38 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrstr(const char *haystack, const char *needle)
{
	const char	*hs;
	const char	*ne;
	char		*buf;

	buf = 0;
	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle && *haystack)
		{
			hs = haystack;
			ne = needle;
			while (*(ne++) == *(hs++))
				if (!*ne)
					buf = (char*)haystack;
		}
		++haystack;
	}
	return (buf);
}
