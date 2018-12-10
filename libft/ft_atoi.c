/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:00:55 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/19 09:34:15 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_long(long unsigned int ui, const char sign)
{
	if (sign == -1 && ui > 9223372036854775807)
		return (0);
	if (sign == 1 && ui > 9223372036854775806)
		return (-1);
	return (ui * sign);
}

int			ft_atoi(const char *src)
{
	char				sign;
	long unsigned int	ui;

	while ((*src >= 9 && *src <= 13) || *src == ' ')
		src++;
	ui = 0;
	sign = 1;
	if (*src == '+' || *src == '-')
		sign = 1 - 2 * (*(src++) == '-');
	while ('0' <= *src && *src <= '9')
		ui = ui * 10 + *(src++) - '0';
	return (check_long(ui, sign));
}
