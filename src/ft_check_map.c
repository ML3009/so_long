/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:12:33 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/23 17:23:10 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map(t_vars *var, char *str)
{
	if (ft_check_size(var) == 0)
	{
		ft_putstr_fd("Error\nWrong map size\n", 2);
		ft_free_tab(var->map);
		ft_free_tab(var->map_copy);
		exit (1);
	}
	if (ft_check_wall(var, str) == 0)
	{
		ft_putstr_fd("Error\nWrong wall placement\n", 2);
		ft_free_tab(var->map);
		ft_free_tab(var->map_copy);
		exit (1);
	}
	ft_check_map2(var);
	return (1);
}

int	ft_check_map2(t_vars *var)
{
	if (ft_check_parsing(var) == 0)
	{
		ft_putstr_fd("Error\nUnknow character\n", 2);
		ft_free_tab(var->map);
		ft_free_tab(var->map_copy);
		exit (1);
	}
	if (ft_check_occurence(var) == 0)
	{
		ft_putstr_fd("Error\nProblem with occurence\n", 2);
		ft_free_tab(var->map);
		ft_free_tab(var->map_copy);
		exit (1);
	}
	return (1);
}
