/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:39:02 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/28 17:40:42 by jubonill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_H
#	define FT_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>
#include <stdio.h>

#define BUF_SIZE 30000

int		ft_strlen(char *error);
void	ft_print_error(char *filename, int err);
int		is_dir(char *s);
void	ft_check_read(char *paths[], int ac);
int		check_dash(char *av1, char *av2, int ac);

#	endif
