/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:08:46 by rballant          #+#    #+#             */
/*   Updated: 2020/10/17 16:03:41 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_solo_l(char ***tab, int i, int num)
{
	int k;
	int j;

	j = 0;
	k = 0;
	while (!tab[i][j][num])
		j++;
	while (k < 4)
	{
		if (k != num)
			tab[i][j][k] = 0;
		k++;
	}
}

void	ft_solo_c(char ***tab, int i, int num)
{
	int k;
	int j;

	j = 0;
	k = 0;
	while (!tab[j][i][num])
		j++;
	while (k < 4)
	{
		if (k != num)
			tab[j][i][k] = 0;
		k++;
	}
}

void	ft_solo(char ***tab)
{
	int i;
	int num;

	i = 0;
	while (i < 4)
	{
		num = 0;
		while (num < 4)
		{
			if (tab[i][0][num] + tab[i][1][num]
					+ tab[i][2][num] + tab[i][3][num] == 1)
				ft_solo_l(tab, i, num);
			if (tab[0][i][num] + tab[1][i][num]
					+ tab[2][i][num] + tab[3][i][num] == 1)
				ft_solo_c(tab, i, num);
			num++;
		}
		i++;
	}
}
