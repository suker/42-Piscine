/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:52:47 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/17 19:44:05 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char *av[])
{
	int i;
	int k;

	i = 1;
	if (ac > 1)
	{
		while (ac > 1)
		{
			k = -1;
			while (av[ac - 1][++k] != '\0')
				ft_putchar(av[ac - 1][k]);
			ft_putchar('\n');
			ac--;
		}
	}
	return (0);
}
