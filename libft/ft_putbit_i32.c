/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:08:50 by aulopez           #+#    #+#             */
/*   Updated: 2018/12/03 15:48:37 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbit_i32(unsigned int i, size_t size, char one, char zero)
{
	unsigned int	j;

	j = 2147483648;
	while (j && size--)
	{
		if (j <= i)
		{
			ft_putchar(one);
			i -= j;
		}
		else
			ft_putchar(zero);
		j /= 2;
	}
}
