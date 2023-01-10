/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:12:33 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 11:42:29 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

int ft_check_map (char **str, char *map)
{
	if (ft_check_size(str) == 0)
	{
		ft_putstr_fd("Error\nWrong map size\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	if (ft_check_wall(str, map) == 0)
	{
		ft_putstr_fd("Error\nWrong wall placement\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	if (ft_check_parsing(str) == 0)
	{
		ft_putstr_fd("Error\nUnknow character\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	if (ft_check_occurence(str) == 0)
	{
		ft_putstr_fd("Error\nProblem with CEP\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	return(1);
}

