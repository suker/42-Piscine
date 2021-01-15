/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:36:10 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/26 20:00:03 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		min;
	int		len;

	i = 0;
	len = 0;
	while (tab[len])
		len++;
	while (i < len - 1)
	{
		j = i + 1;
		min = i;
		while (j < len)
		{
			if (ft_strcmp(tab[min], tab[j]) > 0)
				min = j;
			j++;
		}
		if (ft_strcmp(tab[i], tab[min]) > 0)
			ft_swap(tab, i, min);
		i++;
	}
}
