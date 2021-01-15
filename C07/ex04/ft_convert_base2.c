/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:32:42 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/24 20:14:13 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_base(char c, char *base);
int		is_space(char c);

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		index_of_base(unsigned char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int i;
	int base_len;
	int num;

	num = 0;
	base_len = check_base(base);
	sign = 0;
	if (!base_len)
		return (0);
	while ((*str == '\t' || *str == '\v' || *str == '\f' || *str == '\n' || \
			*str == '\r' || *str == ' ') && *str)
		str++;
	while ((*str == '+' || *str == '-') && *str)
	{
		if (*str++ == '-')
			sign++;
	}
	i = 0;
	while (is_in_base(str[i], base) && str[i])
	{
		num = (num * base_len) + (index_of_base(str[i], base));
		i++;
	}
	return (num * ((sign % 2 == 1) ? -1 : 1));
}

void	ft_rev_s(char *tab)
{
	int temp;
	int i;
	int half;
	int size;

	i = 0;
	temp = 0;
	size = 0;
	while (tab[i++])
		size++;
	i = 0;
	half = size / 2;
	if (*tab == '-')
		i++;
	while (half-- > 0)
	{
		temp = tab[i];
		tab[i++] = tab[size - 1];
		tab[size-- - 1] = temp;
	}
}

char	*itoa(int nb, int len_base, char *base)
{
	int				i;
	unsigned int	n;
	char			*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * 34)))
		return (0);
	i = 0;
	if (nb < 0)
	{
		tmp[i++] = '-';
		n = nb * -1;
	}
	else
		n = nb;
	if (n == 0)
		tmp[i++] = base[0];
	while (n)
	{
		tmp[i++] = base[n % len_base];
		n /= len_base;
	}
	tmp[i] = '\0';
	ft_rev_s(tmp);
	return (tmp);
}
