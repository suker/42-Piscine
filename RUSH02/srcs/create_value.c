/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:00:33 by ldelmas           #+#    #+#             */
/*   Updated: 2020/10/25 19:05:49 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

char	*put_n_zeros(int n, char *dest)
{
	int i;

	i = 0;
	while (i < n)
	{
		dest = ft_strcat(dest, "0");
		i++;
	}
	return (dest);
}

char	*create_ten_power(int n)
{
	int		i;
	char	*str;

	if (n <= 3)
		str = (char *)malloc(sizeof(char) * (n + 2));
	else
		str = (char *)malloc(sizeof(char) * (3 + ((n - 3) * 3) + 2));
	str[0] = '1';
	str[1] = 0;
	i = 1;
	while (i <= n)
	{
		str = put_n_zeros(1, str);
		i++;
	}
	if (n > 3)
	{
		i = 0;
		while (i + 3 < n)
		{
			str = put_n_zeros(2, str);
			i++;
		}
	}
	return (str);
}

int		alloc_str_space(char **str, int size)
{
	*str = (char *)malloc(sizeof(char) * size);
	return (size);
}

char	*give_nbr(char *str, int i)
{
	if (i <= 9)
		str[0] = i + '0';
	else if (i <= 19)
	{
		str[0] = (i / 10) + '0';
		str[1] = (i % 10) + '0';
	}
	else if (i < 28)
	{
		str[0] = (i / 10) + (i % 10) + '0';
		str[1] = '0';
	}
	return (str);
}

char	*create_number(int i)
{
	char	*str;
	int		size;

	if (i <= 9)
	{
		size = alloc_str_space(&str, 2);
		str = give_nbr(str, i);
	}
	else if (i <= 19)
	{
		size = alloc_str_space(&str, 3);
		str = give_nbr(str, i);
	}
	else if (i < 28)
	{
		size = alloc_str_space(&str, 3);
		str = give_nbr(str, i);
	}
	else
	{
		str = create_ten_power(i - 26);
		size = ft_strlen(str) + 1;
	}
	str[size - 1] = '\0';
	return (str);
}
