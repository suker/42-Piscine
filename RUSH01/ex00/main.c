/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:15:30 by rballant          #+#    #+#             */
/*   Updated: 2020/10/18 19:45:52 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_valid.h"
#include "ft_match.h"

char	***ft_init(void)
{
	char	***tab;
	int		i;
	int		j;
	int		k;

	tab = (char ***)malloc(4 * sizeof(void *));
	i = 0;
	while (i < 4)
	{
		j = 0;
		tab[i] = (char **)malloc(4 * sizeof(void *));
		while (j < 4)
		{
			tab[i][j] = (char *)malloc(4 * sizeof(char));
			k = 0;
			while (k < 4)
			{
				tab[i][j][k] = 1;
				k++;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int		main(int argc, char *argv[])
{
	int		*input;
	int		count;
	char	***tab;
	char	****tab_tab;

	input = to_int_array(argv[1], argc);
	if (*input == 0)
		return (0);
	tab = ft_init();
	ft_match(tab, input);
	count = 15;
	while (ft_check_uncertainty(tab) - count)
	{
		count = ft_check_uncertainty(tab);
		ft_clean(tab);
		ft_solo(tab);
	}
	if (!(ft_check_uncertainty(tab)) && ft_valid(tab, input))
	{
		ft_puttab(tab);
		return (0);
	}
	tab_tab = (char ****)malloc(64 * sizeof(void *));
	tab_tab = &tab;
	ft_back_tracking(tab_tab, 0, input);
}
