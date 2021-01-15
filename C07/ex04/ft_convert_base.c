/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:34:34 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/24 20:13:47 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*itoa(int nb, int len_base, char *base);
int		ft_atoi_base(char *str, char *base);
int		check_base(char *base);

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int		ft_digits(int nb)
{
	int c;

	c = 1;
	if (nb < 0)
		nb *= -1;
	while (nb / 10 >= 1)
	{
		c++;
		nb /= 10;
	}
	return (c);
}

int		is_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\n' || \
			c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*sol;
	int		num_len;
	int		num_int;
	int		len_base;

	if (check_base(base_from) && check_base(base_to))
	{
		len_base = ft_strlen(base_to);
		num_int = ft_atoi_base(nbr, base_from);
		num_len = ft_digits(num_int);
		sol = (char *)malloc(sizeof(char) * 34);
		if (!sol)
			return (0);
		sol = itoa(num_int, len_base, base_to);
		return (sol);
	}
	else
		return (0);
}
