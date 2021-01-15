/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:07:32 by tderwedu          #+#    #+#             */
/*   Updated: 2020/10/18 19:41:55 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_match_needs.h"

void	ft_apply_val(char ***tab, int i, int j, int k)
{
	int val;
	int index;

	val = -1;
	index = -1;
	while (++val < 4)
	{
		if (val != k)
			tab[i][j][val] = 0;
	}
	while (++index < 4)
	{
		if (index != j)
			tab[i][index][k] = 0;
	}
	index = -1;
	while (++index < 4)
	{
		if (index != i)
			tab[index][j][k] = 0;
	}
}

void	ft_rows_restrictions(char ***tab, int i, int val)
{
	if (val == 12)
		ft_row_1221(tab, i, 1);
	else if (val == 21)
		ft_row_1221(tab, i, -1);
	else if (val == 13)
		ft_row_1331(tab, i, 1);
	else if (val == 31)
		ft_row_1331(tab, i, -1);
	else if (val == 14)
		ft_row_1441(tab, i, 1);
	else if (val == 41)
		ft_row_1441(tab, i, -1);
	else if (val == 22)
		ft_row_22(tab, i);
	else if (val == 23)
		ft_row_2332(tab, i, 1);
	else if (val == 32)
		ft_row_2332(tab, i, -1);
}

void	ft_columns_restrictions(char ***tab, int j, int val)
{
	if (val == 12)
		ft_column_1221(tab, j, 1);
	else if (val == 21)
		ft_column_1221(tab, j, -1);
	else if (val == 13)
		ft_column_1331(tab, j, 1);
	else if (val == 31)
		ft_column_1331(tab, j, -1);
	else if (val == 14)
		ft_column_1441(tab, j, 1);
	else if (val == 41)
		ft_column_1441(tab, j, -1);
	else if (val == 22)
		ft_column_22(tab, j);
	else if (val == 23)
		ft_column_2332(tab, j, 1);
	else if (val == 32)
		ft_column_2332(tab, j, -1);
}

void	ft_match(char ***tab, int *intput)
{
	int index;

	index = -1;
	while (++index < 4)
	{
		ft_columns_restrictions(tab, index, intput[index]);
	}
	index--;
	while (++index < 8)
	{
		ft_rows_restrictions(tab, index - 4, intput[index]);
	}
}
