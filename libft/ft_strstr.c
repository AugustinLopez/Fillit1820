/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:22:00 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/15 09:33:15 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*hs;
	const char	*ne;

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
					return ((char*)haystack);
		}
		++haystack;
	}
	return (0);
}
