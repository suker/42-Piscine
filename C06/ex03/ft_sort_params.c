/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:14:39 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/18 11:29:58 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

void	ft_swap(char *arr[], int idx, int min)
{
	char *temp;

	temp = arr[idx];
	arr[idx] = arr[min];
	arr[min] = temp;
}

void	ft_sort(char *av[], int size)
{
	int				i;
	int				j;
	int				min;

	i = 1;
	while (i < size - 1)
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (ft_strcmp(av[min], av[j]) > 0)
				min = j;
			j++;
		}
		if (ft_strcmp(av[i], av[min]) >= 0)
			ft_swap(av, i, min);
		i++;
	}
}

int		main(int ac, char *av[])
{
	int i;
	int k;

	i = 1;
	if (ac > 1)
	{
		ft_sort(av, ac);
		while (i < ac)
		{
			k = -1;
			while (av[i][++k] != '\0')
				ft_putchar(av[i][k]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
