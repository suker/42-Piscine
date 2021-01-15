/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:44:46 by rballant          #+#    #+#             */
/*   Updated: 2020/10/18 19:45:26 by rballant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATCH_H
# define FT_MATCH_H

int		*to_int_array(char *av, int ac);
void	ft_match(char ***tab, int *input);
void	ft_back_tracking(char ****tab_tab, int n, int *input);
int		ft_check_uncertainty(char ***new_tab);
#endif
