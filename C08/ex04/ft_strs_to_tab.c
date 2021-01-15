/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:35:41 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/22 15:31:52 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = -1;
	res = malloc(sizeof(*src));
	if (res == 0)
		return (0);
	while (src[++i] != '\0')
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;
	int					len;

	if (!(res = (struct s_stock_str *)malloc(sizeof(*res) * (ac + 1))))
		return (0);
	i = -1;
	while (++i < ac)
	{
		len = ft_strlen(av[i]);
		res[i].size = len;
		if (!(res[i].str = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		res[i].str = av[i];
		if (!(res[i].copy = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		res[i].copy = ft_strdup(av[i]);
	}
	res[i].str = NULL;
	return (res);
}
