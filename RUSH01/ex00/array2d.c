/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Darray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:30:16 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/17 17:49:39 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_input_len(char *av)
{
	int len;

	len = 0;
	while (av[len] != '\0')
		len++;
	if (len != 31)
		return (0);
	return (1);
}

int		is_valid_input(char *av)
{
	int i;

	i = 0;
	if (check_input_len(av))
	{
		while (av[i] != '\0')
		{
			if (i % 2 == 0)
			{
				if (av[i] < '1' || av[i] > '4')
					return (0);
			}
			else if (i % 2 == 1)
			{
				if (av[i] != ' ')
					return (0);
			}
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int		is_valid_values(char *av)
{
	int i;

	i = 0;
	if (is_valid_input(av))
	{
		while (i < 23)
		{
			if (((av[i] - 48) + (av[i + 8] - 48)) < 3 || \
					((av[i] - 48) + (av[i + 8] - 48)) > 5)
				return (0);
			if (i == 6)
				i += 10;
			else
				i += 2;
		}
		return (1);
	}
	else
		return (0);
}

int		*to_int_array(char *av, int ac)
{
	int *arr;
	int i;
	int j;

	j = 0;
	i = 0;
	arr = (int *)malloc(sizeof(int) * 8);
	if (ac == 2 && is_valid_values(av) == 1)
	{
		while (i < 23)
		{
			arr[j++] = ((av[i] - 48) * 10) + (av[i + 8] - 48);
			if (i == 6)
				i += 10;
			else
				i += 2;
		}
		arr[j] = 0;
	}
	else
	{
		*arr = 0;
		write(1, "Error\n", 6);
	}
	return (arr);
}
