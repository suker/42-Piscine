/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tderwedu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:12:02 by tderwedu          #+#    #+#             */
/*   Updated: 2020/10/18 19:44:14 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_valid.h"
#include "ft_apply.h"
#include "ft_check_null.h"

char	***ft_copy_new_tab(char ***old_tab)
{
	char	***new_tab;
	int		i;
	int		j;
	int		k;

	new_tab = (char ***)malloc(4 * sizeof(void *));
	i = -1;
	while (++i < 4)
	{
		j = -1;
		new_tab[i] = (char **)malloc(4 * sizeof(void *));
		while (++j < 4)
		{
			new_tab[i][j] = (char *)malloc(4 * sizeof(char));
			k = -1;
			while (++k < 4)
				new_tab[i][j][k] = old_tab[i][j][k];
		}
	}
	return (new_tab);
}

char	***ft_rm_1_uncertainty(char ***tab)
{
	int		ijk[3];
	int		keep_searching;
	char	***new_tab;

	new_tab = ft_copy_new_tab(tab);
	keep_searching = 1;
	ijk[0] = -1;
	while (++ijk[0] < 4 && keep_searching)
	{
		ijk[1] = -1;
		while (++ijk[1] < 4 && keep_searching)
		{
			if ((tab[ijk[0]][ijk[1]][0] + tab[ijk[0]][ijk[1]][1]
						+ tab[ijk[0]][ijk[1]][2] + tab[ijk[0]][ijk[1]][3]) > 1)
			{
				ijk[2] = 0;
				while (!new_tab[ijk[0]][ijk[1]][ijk[2]])
					ijk[2]++;
				tab[ijk[0]][ijk[1]][ijk[2]] = 0;
				ft_apply_val(new_tab, ijk[0], ijk[1], ijk[2]);
				keep_searching = 0;
			}
		}
	}
	return (new_tab);
}

int		ft_check_uncertainty(char ***new_tab)
{
	int		i;
	int		j;
	int		k;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				count += new_tab[i][j][k];
		}
	}
	if (count > 16 && ft_check_null(new_tab))
		return (count);
	else
		return (0);
}

void	ft_back_tracking(char ****tab_tab, int n, int *input)
{
	if (ft_check_uncertainty(tab_tab[n]))
	{
		tab_tab[n + 1] = ft_rm_1_uncertainty(tab_tab[n]);
		ft_clean(tab_tab[n + 1]);
		ft_solo(tab_tab[n + 1]);
		if (ft_check_uncertainty(tab_tab[n + 1]))
			ft_back_tracking(tab_tab, n + 1, input);
		else if (ft_valid(tab_tab[n + 1], input))
			ft_puttab(tab_tab[n + 1]);
		else
			ft_back_tracking(tab_tab, n, input);
	}
	else if (ft_valid(tab_tab[n], input))
		ft_puttab(tab_tab[n]);
	else
		write(1, "Error\n", 6);
}
