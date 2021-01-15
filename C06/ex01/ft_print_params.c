/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:44:46 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/17 19:43:44 by jubonill         ###   ########.fr       */
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
