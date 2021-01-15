/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:44:56 by ldelmas           #+#    #+#             */
/*   Updated: 2020/10/25 19:07:55 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_total_len(char **str, int size, char *sep)
{
	int i;
	int cat_size;

	cat_size = 0;
	i = 0;
	while (i < size)
	{
		cat_size += ft_strlen(str[i]);
		i++;
	}
	cat_size += (size - 1) * ft_strlen(sep) + 1;
	return (cat_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*concat;

	if (size == 0)
	{
		concat = (char *)malloc(sizeof(char));
		*concat = 0;
		return (concat);
	}
	concat = (char *)malloc(sizeof(char) * ft_total_len(strs, size, sep));
	if (!concat)
		return (NULL);
	*concat = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(concat, strs[i]);
		if (i < size - 1)
			ft_strcat(concat, sep);
		i++;
	}
	ft_strcat(concat, "\0");
	return (concat);
}
