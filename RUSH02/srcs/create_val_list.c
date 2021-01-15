/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:56:24 by ldelmas           #+#    #+#             */
/*   Updated: 2020/10/25 19:05:29 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict.h"
#include "../includes/ft.h"
#include "../includes/files.h"

char	**create_list(void)
{
	int		i;
	int		j;
	char	**key_list;

	i = 0;
	j = 0;
	key_list = (char **)malloc(sizeof(char *) * 42);
	while (i < 41)
	{
		key_list[i] = create_number(i);
		i++;
	}
	key_list[i] = (void *)0;
	return (key_list);
}
