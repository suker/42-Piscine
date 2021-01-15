/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:28:38 by tderwedu          #+#    #+#             */
/*   Updated: 2020/10/18 19:36:44 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_apply.h"

void	ft_column_1221(char ***tab, int j, int bool)
{
	int i_3;
	int i_4;

	i_3 = (bool == 1 ? 3 : 0);
	i_4 = (bool == 1 ? 0 : 3);
	ft_apply_val(tab, i_3, j, 2);
	ft_apply_val(tab, i_4, j, 3);
}

void	ft_column_1331(char ***tab, int j, int bool)
{
	if (bool == 1)
	{
		ft_apply_val(tab, 0, j, 3);
		tab[2][j][1] = 0;
		tab[3][j][2] = 0;
	}
	else if (bool == -1)
	{
		tab[0][j][2] = 0;
		tab[1][j][1] = 0;
		ft_apply_val(tab, 3, j, 3);
	}
}

void	ft_column_1441(char ***tab, int j, int bool)
{
	if (bool == 1)
	{
		ft_apply_val(tab, 0, j, 3);
		ft_apply_val(tab, 1, j, 2);
		ft_apply_val(tab, 2, j, 1);
		ft_apply_val(tab, 3, j, 0);
	}
	else if (bool == -1)
	{
		ft_apply_val(tab, 0, j, 0);
		ft_apply_val(tab, 1, j, 1);
		ft_apply_val(tab, 2, j, 2);
		ft_apply_val(tab, 3, j, 3);
	}
}

void	ft_column_22(char ***tab, int j)
{
	tab[0][j][3] = 0;
	tab[1][j][2] = 0;
	tab[2][j][2] = 0;
	tab[3][j][3] = 0;
}

void	ft_column_2332(char ***tab, int j, int bool)
{
	if (bool == 1)
	{
		ft_apply_val(tab, 1, j, 3);
		tab[2][j][0] = 0;
		tab[3][j][2] = 0;
	}
	else if (bool == -1)
	{
		tab[0][j][2] = 0;
		tab[1][j][0] = 0;
		ft_apply_val(tab, 2, j, 3);
	}
}
