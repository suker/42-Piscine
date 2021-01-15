/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 10:37:59 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/25 21:18:33 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

void			get_key_value(char *s, char *key, char *value)
{
	int i;
	int j;

	i = 0;
	j = i;
	while (s[i] >= '0' && s[i] <= '9' && s[i])
		i++;
	ft_strcpy(key, s, j, i);
	while ((s[i] < 33 || s[i] == 127 || s[i] == ':') && s[i])
		i++;
	j = i;
	while (s[i] >= 32 && s[i] <= 126 && s[i])
		i++;
	ft_strcpy(value, s, j, i);
}

struct dict		*ft_get_dict(char **str)
{
	struct dict	*d;
	int			i;

	i = 0;
	if (!(d = (struct dict *)malloc(sizeof(struct dict) * 42)))
		return (0);
	while (i < 41)
	{
		if (!(d[i].key = (char *)malloc(sizeof(char) * 100)))
			return (0);
		if (!(d[i].value = (char *)malloc(sizeof(char) * 100)))
			return (0);
		get_key_value(*str, d[i].key, d[i].value);
		i++;
		str++;
	}
	d[i].key = 0;
	d[i].value = 0;
	return (d);
}

char			**read_file(char *path, char *charset)
{
	int		fd;
	char	*join;
	char	buf[MAX_BYTES];
	char	**s2;
	int		size;

	fd = open(path, O_RDWR);
	while (read(fd, buf, MAX_BYTES))
	{
		size = count_words(buf, charset);
		join = ft_strjoin(size, ft_split(buf, charset), " ");
	}
	s2 = ft_split(join, "\n");
	free(join);
	return (s2);
}
