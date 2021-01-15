/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:59:33 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/28 18:07:33 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		ft_atoi(char *str)
{
	int sign;
	int i;
	int base;
	int num;

	num = 0;
	base = 1;
	sign = 0;
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\n' || \
			*str == '\r' || *str == ' ') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str++ == '-')
			sign++;
	}
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9' && str[i])
		num = (num * 10) + (str[i] - '0');
	return (num * ((sign % 2 == 1) ? -1 : 1));
}

int		ft_operation(char op, int a, int b)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	if (op == '%')
		return (a % b);
	return (0);
}

int		is_valid_operator(char *s)
{
	int i;

	i = 0;
	if (s[i] == '*' || s[i] == '+' || s[i] == '%' || \
			s[i] == '-' || s[i] == '/')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int		main(int ac, char *av[])
{
	if (ac == 4)
	{
		if (is_valid_operator(av[2]))
		{
			if (av[2][0] == '/' && ft_atoi(av[3]) == 0)
				write(1, "Stop: division by zero\n", 23);
			else if (av[2][0] == '%' && ft_atoi(av[3]) == 0)
				write(1, "Stop: modulo by zero\n", 21);
			else
			{
				ft_putnbr(ft_operation(av[2][0], \
							ft_atoi(av[1]), ft_atoi(av[3])));
				write(1, "\n", 1);
			}
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
