/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:52:31 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/25 21:19:10 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

int		file_validation(char *path)
{
	int		fd;
	char	buf[MAX_BYTES + 1];
	int		ret;

	if (*path == 0)
		return (0);
	if (!(fd = open(path, O_RDWR)))
		return (0);
	while ((ret = read(fd, buf, 1)))
	{
		if (ret > MAX_BYTES)
			return (0);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || \
			c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		check_dict(char *buf)
{
	int i;

	i = 0;
	if (*buf == '\n')
		return (1);
	if (buf[0] < '0' || buf[0] > '9')
		return (0);
	while (buf[i] >= '0' && buf[i] <= '9' && buf[i] != ':')
		i++;
	if (buf[i] != ':')
	{
		while (is_space(buf[i]) && buf[i])
			i++;
	}
	if (buf[i] == ':')
		i++;
	while (is_space(buf[i]) && buf[i])
		i++;
	while (buf[i] >= 32 && buf[i] <= 126 && buf[i])
		i++;
	if (buf[i] == '\0')
		return (1);
	else
		return (0);
}

int		is_valid_dict(char *path)
{
	int		fd;
	char	buf[MAX_BYTES];
	char	**s1;
	int		i;

	i = 0;
	if (!(fd = open(path, O_RDWR)))
		return (0);
	while (read(fd, buf, MAX_BYTES))
		s1 = ft_split(buf, "\n");
	close(fd);
	while (s1[i])
	{
		if (check_dict(s1[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
