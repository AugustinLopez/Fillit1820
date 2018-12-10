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
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>


static void	assign_uint16_value(uint16_t *a, uint16_t *b, uint16_t *c,
								uint16_t *d)
{
	if (*a + *b + *c + *d > 15)
	{
		*d = *d >> 1;
		if (*d == 0)
		{
			*c = *c >> 1;
			if (*c == 1)
			{
				*b = *b >> 1;
				if (*b == 2)
				{
					*a = *a >> 1;
					*b = *a >> 1;
				}
				*c = *b >> 1;
			}
			*d = *c >> 1;
		}
	}
}

static int		create_piece(int i, char **pie)
{
	static uint16_t a = 0b1000000000000000;
	static uint16_t b = 0b100000000000000;
	static uint16_t c = 0b10000000000000;
	static uint16_t d = 0b1000000000000;
	int				j;

	if (i == 0)
	{
		*pie = ft_strdup("####\n....\n....\n....");
		return (a + b + c + d);
	}
	assign_uint16_value(&a, &b, &c, &d);
	*pie = ft_strdup("....\n....\n....\n....");
	i = 0b10000000000000000;
	j = 0;
	while ((i = i >> 1))
	{
		if (i & (a + b + c + d))
			(*pie)[j] = '#';
		j++;
		if ((*pie)[j] == '\n')
			j++;
	}
	return (a + b + c + d);
}

static int	handle_pipe(int option, char (*txt)[20])
{
	static int	out_pipe[2];
	static int	saved_stdout;

	if (option == 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		if (pipe(out_pipe) != 0)
		{
			dup2(saved_stdout, STDOUT_FILENO);
			ft_putstr("Error: cannot load stdout into a pipe.\n");
			return (-1);
		}
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[1]);
		return (0);
	}
	if (option == 1)
	{
		fflush(stdout);
		read(out_pipe[0], *txt, 20);
		return (0);
	}
	if (option == 2)
			dup2(saved_stdout, STDOUT_FILENO);
	return (0);
}

static int	get_valid(char	(*buf)[50], int fd, char *piece, char (*buffer)[20])
{
	char	*tmp;
	int		i;

	i = 0;
	ft_strclr(*buf);
	while (i++ < 3)
	{
		get_next_line(fd, &tmp);
		ft_strcat(ft_strcat(*buf, tmp), "\n");
		free(tmp);
	}
	get_next_line(fd, &tmp);
	ft_strcat(*buf, tmp);
	free(tmp);
	if (ft_strcmp(*buf, piece))
	{
		ft_putendl("Error : the piece was :");
		ft_putendl(piece);
		ft_putendl("\n\nAnd here's what your fillit gives :");
		ft_putendl(*buffer);
		return (-1);
	}
	get_next_line(fd, &tmp);
	free(tmp);
	return (0);
}


static char	*path_to_fillit(char **argv)
{
	char	*tmp;
	char	*sys;

	if(!(tmp = ft_strjoin("./", argv[1])))
	{
		ft_putendl("Error: failed malloc.");
		return (0);
	}
	if(!(sys = ft_strjoin(tmp, " piece.txt")))
		ft_putendl("Error: failed malloc.");
	free(tmp);
	return (sys);
}

int		main(int argc, char **argv)
{
	char	*sys;
	char	*tmp;
	char	tmp3[50];
	int		fd;
	int		gnl;
	int		yrs;
	int		i;
	char	buffer[20] = {0};

	if (argc != 2)
	{
		ft_putendl("Usage : ./Fillit1820 path_to_fillit");
		return (0);
	}
	if ((gnl = open("valid.txt", O_RDONLY)) == -1)
	{
		ft_putendl("Error : cannot open valid.txt");
		return (-1);
	}
	if (!(sys = path_to_fillit(argv)))
		return (-1);
	if ((handle_pipe(0, 0)))
		return (-1);
	i = -1;
	while (i++ < 1819)
	{
		create_piece(i, &tmp);
		fd = open("piece.txt", O_RDWR | O_CREAT | O_TRUNC, 666);
		if (fd == -1)
		{
			handle_pipe(2, 0);
			ft_putstr("Error : cannot open piece.txt. Index: ");
			ft_putnbr(i);
			ft_putchar('\n');
			return (-1);
		}
		ft_putstr_fd(tmp, fd);
		close(fd);
		system(sys);
		ft_strclr(buffer);
		handle_pipe(1, &buffer);
		if (buffer[0] != 'e')
			if(get_valid(&tmp3, gnl, tmp, &buffer))
				return (-1);
		free(tmp);
	}
	handle_pipe(2, 0);
	printf("Congratulations, your fillit works with basic inputs !\n");
	free(sys);
	return (0);
}

