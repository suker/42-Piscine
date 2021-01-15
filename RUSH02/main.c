/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubonill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:42:08 by jubonill          #+#    #+#             */
/*   Updated: 2020/10/25 20:25:19 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/files.h"
#include "includes/ft.h"
#include "includes/dict.h"

void	ft_show_tab(struct dict *par);

/*check if the argument is a proper positive integer*/
int		check_valid_num(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*check the number of parameters and gives the name of the dictionnary*/
char	*read_param(int ac, char *av[])
{
	char *name;

	name = (char *)malloc(sizeof(char) * 30);
	name = "";
	if (ac == 2)
	{
		if (!check_valid_num(av[1]))
			return (name);
		name = "numbers.dict";	
		return (name);
	}
	else if (ac == 3)
	{
		if (!check_valid_num(av[2]))
			return (name);
		return (av[1]);
	}
	else
		return (name);
}

int		main(int ac, char *av[])
{
	char 		*dict_name;
	struct dict *d;
	char		charset[] = {'\t', '\v', '\r', '\f', ' ', 0};

	dict_name = read_param(ac, av);
	if (file_validation(dict_name))
	{
	//	if (is_valid_dict(dict_name))
	//	{
		// our code goes here
		//d =  ft_get_dict(read_file(dict_name, charset));
		//ft_show_tab(d);
	//	}
	//	else
	//		ft_putstr("Dict Error\n");

		/*start our functions here*/
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
