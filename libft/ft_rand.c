/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:17:08 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/20 10:17:32 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned long long	xor64(unsigned long long x)
{
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return (x);
}

unsigned long				ft_rand(unsigned long long seed)
{
	static unsigned long long	s0 = 11956449406065;
	static unsigned long long	s1 = 35468794565487;
	unsigned long long			x;
	unsigned long long			y;

	if (seed)
	{
		s0 = xor64(xor64(seed));
		s1 = xor64(xor64(s0));
	}
	x = s0;
	y = s1;
	s0 = y;
	x ^= x << 23;
	s1 = x ^ y ^ (x >> 17) ^ (y >> 26);
	return ((unsigned long)(s1 + y));
}
