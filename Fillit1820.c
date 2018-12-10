/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fillit1820.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulopez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:08:05 by aulopez           #+#    #+#             */
/*   Updated: 2018/12/10 16:28:51 by aulopez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		piece(int i, char **pie)
{
	static uint16_t a = 0b1000000000000000;
	static uint16_t b = 0b100000000000000;
	static uint16_t c = 0b10000000000000;
	static uint16_t d = 0b1000000000000;
	uint16_t		e;
	int				j;

	e = a + b + c + d;
	if (i == 0)
	{
		*pie = ft_strdup("####\n....\n....\n....");
		return (a + b + c + d);
	}
	if (e > 15)
	{
		d = d >> 1;
		if (d == 0)
		{
			c = c >> 1;
			if (c == 1)
			{
				b = b >> 1;
				if (b == 2)
				{
					a = a >> 1;
					b = a >> 1;
				}
				c = b >> 1;
			}
			d = c >> 1;
		}
	}
	*pie = ft_strdup("....\n....\n....\n....");
	i = 0b10000000000000000;
	e = a + b + c + d;
	j = 0;
	while ((i = i >> 1))
	{
		if (i & e)
		{
			(*pie)[j] = '#';
		}
		j++;
		if ((*pie)[j] == '\n')
			j++;
	}
	return (e);
}

int		main(int argc, char **argv)
{
	int		status;
	char	*sys;
	char	*tmp;
	int		fd;
	int		i;
	int		j;
	char	buffer[21] = {0};
	char	blabla[10000] = {0};
	char	cmp[10000] = {0};
	int		out_pipe[2];
	int		saved_stdout;

	if (argc != 2)
	{
		write(1, "Usage : ./Fillit1820 path_to_fillit\n", 36);
		return (0);
	}
	tmp = ft_strjoin("./", argv[1]);
	sys = ft_strjoin(tmp, " piece.txt");
	free(tmp);
	saved_stdout = dup(STDOUT_FILENO);
	if (pipe(out_pipe) != 0)
		return (-1);
	dup2(out_pipe[1], STDOUT_FILENO);
	close(out_pipe[1]);
	i = -1;
	j = 0;
	while (i++ < 1819)
	{
		piece(i, &tmp);
		fd = open("piece.txt", O_RDWR | O_CREAT | O_TRUNC | S_IWUSR | S_IRUSR);
		write(fd, tmp, ft_strlen(tmp));
		close(fd);
		status = system(sys);
		fflush(stdout);
		read(out_pipe[0], buffer, 20);
		if (buffer[0] != 'e')
		{
			ft_strcat(blabla, tmp);
			ft_strcat(blabla, "\n\n");
		}
		free(tmp);
	}
	dup2(saved_stdout, STDOUT_FILENO);
	fd = open("valid.txt", O_RDONLY);
	while (get_next_line(fd, &tmp))
	{
		ft_strcat(cmp, tmp);
		ft_strcat(cmp, "\n");
		free(tmp);
	}
	if (ft_strcmp(cmp, blabla) == 0)
		printf("beautiful !\n");
	free(sys);
	return (0);
}
