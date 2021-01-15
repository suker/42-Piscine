/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:41:35 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/16 19:44:20 by jubonill         ###   ########.fr       */
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

	i = -1;
	if (ac > 0)
	{
		while (av[0][++i] != '\0')
			ft_putchar(av[0][i]);
		ft_putchar('\n');
	}
	return (0);
}
