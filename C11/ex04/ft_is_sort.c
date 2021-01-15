/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:52:08 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/27 14:35:59 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_desc(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;

	i = -1;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if ((*f)(tab[i], tab[j]) < 0)
				return (0);
		}
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = -1;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if ((*f)(tab[i], tab[j]) > 0)
			{
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
			break ;
	}
	if (flag)
		return (check_desc(tab, length, (*f)));
	return (1);
}
