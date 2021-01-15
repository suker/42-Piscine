/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:31:57 by vmusunga          #+#    #+#             */
/*   Updated: 2020/10/18 15:35:08 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_k(char *tab)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (tab[k] == 1)
			return (k);
		k++;
	}
	return (0);
}

void	ft_erase(char ***tab, int i, int j, int k)
{
	int ligne;
	int colonne;

	ligne = 0;
	while (ligne < 4)
	{
		if (ligne != i)
			tab[ligne][j][k] = 0;
		ligne++;
	}
	colonne = 0;
	while (colonne < 4)
	{
		if (colonne != j)
			tab[i][colonne][k] = 0;
		colonne++;
	}
}

void	ft_clean(char ***tab)
{
	int i;
	int j;
	int k;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[i][j][0] + tab[i][j][1]
					+ tab[i][j][2] + tab[i][j][3] == 1)
			{
				k = ft_find_k(tab[i][j]);
				ft_erase(tab, i, j, k);
			}
			i++;
		}
		j++;
	}
}
