/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:13:30 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/28 17:42:53 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int ac, char *av[])
{
	int ret;

	ret = check_dash(av[1], av[2], ac);
	if (ret == 1)
	{
		ft_check_read(av, ac);
	}
	else if (ret != -42)
	{
		while (1)
			continue ;
	}
	return (0);
}
