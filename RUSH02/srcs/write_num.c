/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:26:59 by ldelmas           #+#    #+#             */
/*   Updated: 2020/10/25 19:21:34 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

void	write_number(char c, char **dict)
{
	char *num;

	num = dict[c - '0'];
	if (c != '0')
	{
		ft_putstr(num);
		write(1, " ", 1);
	}
}

void	write_last_number(char *str, char **dict, int i)
{
	char *num;

	num = dict[str[i] - '0'];
	if (str[i] != '0')
	{
		ft_putstr(num);
		if (str[i + 1])
			write(1, " ", 1);
	}
}

void	write_hundred(char c, char **dict)
{
	if (c != '0')
	{
		write_number(c, dict);
		ft_putstr(dict[28]);
		write(1, " ", 1);
	}
}

int		write_dozen(char *c, char **dict)
{
	char	*num;

	if (c[0] == '1')
	{
		num = dict[10 + c[1] - '0'];
		ft_putstr(num);
		write(1, " ", 1);
		return (1);
	}
	else if (c[0] == '0')
		return (0);
	else
	{
		num = dict[18 + c[0] - '0'];
		ft_putstr(num);
		write(1, " ", 1);
		return (0);
	}
}

void	write_illion(char *c, char **dict, int pos)
{
	if (c[0] != '0' || c[1] != '0' || c[2] != '0')
	{
		ft_putstr(dict[28 + (pos) / 3]);
		write(1, " ", 1);
	}
}
