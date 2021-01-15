/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:57:20 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/25 19:14:36 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#	ifndef FT_H
#	define FT_H

void		ft_putchar(char c);
void		ft_swap(int *a, int *b);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_putnbr(int nb);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
char		*ft_strjoin(int size, char **strs, char *sep);
char		**ft_split(char *str, char *charset);
int			count_words(char *str, char *cs);
char		*ft_strcpy(char *dest, char *src, int k, int j);

/*Validation file and dictionary prototypes*/
int			file_validation(char *path);
int			is_space(char c);
int			check_dict(char *buf);
int			is_valid_dict(char *path);
void		get_key_value(char *s, char *key, char *value);
struct dict	*ft_get_dict(char **str);
char		**read_file(char *path, char *charset);

/*  */
void	write_number(char c, char **dict);
void	write_last_number(char *str, char **dict, int i);
void	write_hundred(char c, char **dict);
int		write_dozen(char *c, char **dict);
void	write_illion(char *c, char **dict, int pos);
void	translate_by_pos(int *i, int ln, char **dict, char *nbr);
void	translate_nbr(char *nbr, char *dict[42]);
char	*put_n_zeros(int n, char *dest);
char	*create_ten_power(int n);
int		alloc_str_space(char **str, int size);
char	*create_number(int i);
char	**create_list(void);

#	endif
