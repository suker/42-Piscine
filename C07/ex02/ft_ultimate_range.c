/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:57:02 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/20 19:45:53 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *ptr;
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	ptr = (int *)malloc(sizeof(**range) * (max - min));
	if (!ptr)
		return (0);
	i = 0;
	while (min < max)
	{
		ptr[i++] = min;
		min++;
	}
	*range = ptr;
	return (i);
}
