/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:18:12 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/20 17:27:31 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_BOOLEAN_H
#	define FT_BOOLEAN_H

#include <unistd.h>

typedef	int		t_bool;
#define EVEN(x) (x % 2 == 0) ? 1 : 0
#define TRUE 1
#define FALSE 0
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0

#	endif
