/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:58:36 by aulopez           #+#    #+#             */
/*   Updated: 2018/12/05 10:42:29 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int		ft_lstdelone_neuron(t_list **alst, int fd)
{
	t_list		*after;
	t_list		*previous;

	previous = *alst;
	after = (*alst)->next;
	if ((int)previous->content_size == fd)
	{
		ft_lstdelone(&previous, *ft_lstfree);
		*alst = after;
		return (0);
	}
	while (after)
	{
		if ((int)after->content_size == fd)
		{
			previous->next = after->next;
			ft_lstdelone(&after, *ft_lstfree);
			return (0);
		}
		after = after->next;
		previous = previous->next;
	}
	return (0);
}

static int		free_mem_and_exit(char **tmp, t_list **alst)
{
	if (tmp && *tmp)
		free(*tmp);
	if (alst && *alst)
		ft_lstdel(alst, *ft_lstfree);
	return (-2);
}

static int		get_neuron_from_memory(t_list **neuron, t_list **memory, int fd,
					char **line)
{
	t_list		*temp;
	char		dummy[1];

	if ((fd < 0 || line == NULL || read(fd, dummy, 0) < 0))
		return (-1);
	temp = *memory;
	while (temp)
	{
		if ((int)temp->content_size == fd)
		{
			*neuron = temp;
			if ((*neuron)->content)
				if (ft_strchr((char*)((*neuron)->content), '\n'))
					return (1);
			return (0);
		}
		temp = temp->next;
	}
	if (!(*neuron = ft_lstnew("", 1)))
		return (-1);
	(*neuron)->content_size = fd;
	ft_lstadd(memory, *neuron);
	*neuron = *memory;
	return (0);
}

static int		ft_new_line(char **s, char **line)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		if (!(*line = ft_strsub(*s, 0, len)))
			return (-1);
		if (!(temp = ft_strdup(*s + len + 1)))
			return (-1);
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else if ((*s)[len] == '\0')
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		ft_strdel(s);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*memory;
	t_list			*neur;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (!(ret = get_neuron_from_memory(&neur, &memory, fd, line)))
	{
		while ((ret = read(fd, buffer, BUFF_SIZE)))
		{
			buffer[ret] = '\0';
			if (!(tmp = ft_strjoin(neur->content, buffer)) || buffer[0] == '\0')
				return (free_mem_and_exit(&tmp, &memory));
			free(neur->content);
			neur->content = tmp;
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	if (ret < 0)
		return (free_mem_and_exit(0, &memory));
	if (ret == 0 && (neur->content == 0 || ((char*)(neur->content))[0] == 0))
		return (ft_lstdelone_neuron(&memory, fd));
	return (ft_new_line((char**)&(neur->content), line));
}
