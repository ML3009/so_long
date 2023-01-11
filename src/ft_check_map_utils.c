/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:31:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 19:03:23 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int ft_check_size (t_vars *var)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen (var->map[0]);
	while (var->map[i])
	{
		if (len != ft_strlen(var->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_check_wall (t_vars *var, char *str)
{
	int i;
	int j;
	int i_max;
	int j_max;

	i_max = ft_line(str) - 1;
	j_max = ft_column(str) - 1;
	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (j < ft_strlen(var->map[i]) - 1)
		{
			if (var->map[0][j] != '1' || var->map[i_max][j] != '1')
				return (0);
			else if (var->map[i][j_max]!= '1' || var->map[i][0] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_parsing(t_vars *var)
{
	int i;
	int j;
	int size;

	size = ft_strlen(var->map[0]);
	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (j < size - 1)
		{
			if (var->map[i][j] != '1' && var->map[i][j] != '0' && var->map[i][j] != 'C'
				&& var->map[i][j] != 'E' && var->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_occurence (t_vars *var)
{
	int i;
	int j;
	//t_utils map;

	//ft_map_init(&map);

	i = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'P')
				var->player++;
			if (var->map[i][j] == 'E')
				var->exit++;
			if (var->map[i][j] == 'C')
				var->collectible++;
			j++;
		}
		i++;
	}
	if (var->player !=1 || var->exit != 1 || var->collectible == 0)
		return(0);
	return (1);
}



