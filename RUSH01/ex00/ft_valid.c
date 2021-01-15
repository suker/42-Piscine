/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:02:10 by rballant          #+#    #+#             */
/*   Updated: 2020/10/18 18:34:19 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num(char *tab)
{
	int i;

	i = 0;
	while (!tab[i])
		i++;
	return (i + 1);
}

int	ft_calc(char ***tab, int i, int bol)
{
	int tot;
	int j;
	int max;

	tot = 0;
	j = -1;
	max = 0;
	if (bol)
	{
		while (++j < 4)
			if (ft_num(tab[i][j]) > max)
				if (tot++ != -42)
					max = ft_num(tab[i][j]);
	}
	else
	{
		j = 4;
		while (--j >= 0)
			if (ft_num(tab[i][j]) > max)
				if (tot++ != -42)
					max = ft_num(tab[i][j]);
	}
	return (tot);
}

int	ft_calc2(char ***tab, int i, int bol)
{
	int tot;
	int j;
	int max;

	tot = 0;
	j = -1;
	max = 0;
	if (bol)
	{
		while (++j < 4)
			if (ft_num(tab[j][i]) > max)
				if (tot++ != -42)
					max = ft_num(tab[j][i]);
	}
	else
	{
		j = 4;
		while (--j >= 0)
			if (ft_num(tab[j][i]) > max)
				if (tot++ != -42)
					max = ft_num(tab[j][i]);
	}
	return (tot);
}

int	ft_tabcmp(int *tab1, int *tab2)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (tab1[i] != tab2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_valid(char ***tab, int *input)
{
	int current[8];
	int i;

	i = 0;
	while (i < 4)
	{
		current[i] = ft_calc2(tab, i, 1) * 10 + ft_calc2(tab, i, 0);
		i++;
	}
	while (i < 8)
	{
		current[i] = ft_calc(tab, i - 4, 1) * 10 + ft_calc(tab, i - 4, 0);
		i++;
	}
	return (ft_tabcmp(current, input));
}
