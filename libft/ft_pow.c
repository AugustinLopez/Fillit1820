/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:16:40 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 10:16:48 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(unsigned int i, int e)
{
	unsigned long int	result;

	if (e == 0 || i == 1)
		return (1);
	if (i == 0)
		return (0);
	if (i > 46340 && e > 1)
		return (-1);
	result = 1;
	while (e--)
	{
		result *= i;
		if (result > 2147483647)
			return (-1);
	}
	return ((int)result);
}
