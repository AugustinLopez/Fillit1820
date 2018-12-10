/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:43:19 by aulopez           #+#    #+#             */
/*   Updated: 2018/11/19 14:05:54 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	temp = (*alst)->next;
	free(*alst);
	while (temp)
	{
		(*alst) = temp;
		del((*alst)->content, (*alst)->content_size);
		temp = (*alst)->next;
		free(*alst);
	}
	*alst = 0;
}
