/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:28:38 by tderwedu          #+#    #+#             */
/*   Updated: 2020/10/18 19:37:10 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_apply.h"

void	ft_row_1221(char ***tab, int i, int bool)
{
	int j_3;
	int j_4;

	j_3 = (bool == 1 ? 3 : 0);
	j_4 = (bool == 1 ? 0 : 3);
	ft_apply_val(tab, i, j_3, 2);
	ft_apply_val(tab, i, j_4, 3);
}

void	ft_row_1331(char ***tab, int i, int bool)
{
	if (bool == 1)
	{
		ft_apply_val(tab, i, 0, 3);
		tab[i][2][1] = 0;
		tab[i][3][2] = 0;
	}
	else if (bool == -1)
	{
		tab[i][0][2] = 0;
		tab[i][1][1] = 0;
		ft_apply_val(tab, i, 3, 3);
	}
}

void	ft_row_1441(char ***tab, int i, int bool)
{
	if (bool == 1)
	{
		ft_apply_val(tab, i, 0, 3);
		ft_apply_val(tab, i, 1, 2);
		ft_apply_val(tab, i, 2, 1);
		ft_apply_val(tab, i, 3, 0);
	}
	else if (bool == -1)
	{
		ft_apply_val(tab, i, 0, 0);
		ft_apply_val(tab, i, 1, 1);
		ft_apply_val(tab, i, 2, 2);
		ft_apply_val(tab, i, 3, 3);
	}
}

void	ft_row_22(char ***tab, int i)
{
	tab[i][0][3] = 0;
	tab[i][1][2] = 0;
	tab[i][2][2] = 0;
	tab[i][3][3] = 0;
}

void	ft_row_2332(char ***tab, int i, int bool)
{
	if (bool == 1)
	{
		ft_apply_val(tab, i, 1, 3);
		tab[i][2][0] = 0;
		tab[i][3][2] = 0;
	}
	else if (bool == -1)
	{
		tab[i][0][2] = 0;
		tab[i][1][0] = 0;
		ft_apply_val(tab, i, 2, 3);
	}
}
