/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:41:43 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/28 17:41:53 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *error)
{
	int i;

	i = 0;
	while (error[i])
		i++;
	return (i);
}

void	ft_print_error(char *filename, int err)
{
	write(1, "cat: ", 5);
	write(1, filename, ft_strlen(filename));
	write(1, ": ", 2);
	if (err == 2)
		write(1, "is a directory\n", 15);
	else
	{
		write(1, (strerror(err)), ft_strlen(strerror(err)));
		write(1, "\n", 1);
	}
}

void	ft_check_read(char *paths[], int ac)
{
	int		fd;
	int		i;
	int		errno;
	char	buffer[BUF_SIZE];

	i = 0;
	while (++i < ac)
	{
		if ((fd = open(basename(paths[i]), O_DIRECTORY)))
		{
			ft_print_error(paths[i], 2);
			close(fd);
			continue ;
		}
		else
			fd = open(basename(paths[i]), O_RDONLY);
		if (fd == -1)
		{
			ft_print_error(paths[i], errno);
			continue ;
		}
		while (read(fd, buffer, 1))
			write(1, &buffer, 1);
		close(fd);
	}
}

int		check_dash(char *av1, char *av2, int ac)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (ac == 1)
		return (0);
	while (av1[i] == '-')
		i++;
	if (av1[i] != '-' && av1[i] != '\0')
		i--;
	if (ac == 3)
	{
		while (av2[j] == '-')
			j++;
	}
	if ((i >= 1 && i <= 2 && j < 2))
		return (0);
	if (i > 2)
	{
		write(1, "cat: illegal option -- -\n", 25);
		write(1, "usage: cat [-benstuv] [file ...]\n", 33);
		return (-42);
	}
	return (1);
}
