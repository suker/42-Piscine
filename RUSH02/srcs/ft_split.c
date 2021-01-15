/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:11:43 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/25 19:06:59 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

int		is_charset(char c, char *cs)
{
	int i;

	i = -1;
	while (cs[++i])
	{
		if (c == cs[i])
			return (1);
	}
	return (0);
}

int		count_words(char *str, char *cs)
{
	int c;
	int i;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (is_charset(str[i], cs) && str[i])
			i++;
		if (!str[i])
			break ;
		while (is_charset(str[i], cs) == 0 && str[i])
			i++;
		c++;
	}
	return (c);
}

char	*ft_strcpy(char *dest, char *src, int k, int j)
{
	int i;

	i = 0;
	while (k < j)
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		get_strings(char **s, char *str, char *cs)
{
	int j;
	int i;
	int k;
	int p;

	p = 0;
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (is_charset(str[i], cs) && str[i])
			i++;
		k = i;
		while (is_charset(str[i], cs) == 0 && str[i])
			i++;
		j = i;
		if (!(s[p] = (char *)malloc(sizeof(char) * (j - k + 1))))
			return (0);
		ft_strcpy(s[p], str, k, j);
		if (str[i] == '\0')
			break ;
		p++;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**s;
	char	*tmp;
	int		num_words;
	int		i;

	tmp = str;
	i = -1;
	num_words = count_words(str, charset);
	if (!(s = (char **)malloc(sizeof(char *) * (num_words + 1))))
		return (0);
	if (!(get_strings(s, tmp, charset)))
		return (0);
	s[num_words] = 0;
	return (s);
}
