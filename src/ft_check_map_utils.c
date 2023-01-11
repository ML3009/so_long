/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:31:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 15:03:54 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int ft_check_size (char **str)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen (str[0]);
	while (str[i])
	{
		if (len != ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_check_wall (char **str, char *map)
{
	int i;
	int j;
	int i_max;
	int j_max;

	i_max = ft_line(map) - 1;
	j_max = ft_column(map) - 1;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < ft_strlen(str[i]) - 1)
		{
			if (str[0][j] != '1' || str[i_max][j] != '1')
				return (0);
			else if (str[i][j_max]!= '1' || str[i][0] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_parsing(char **str)
{
	int i;
	int j;
	int size;

	size = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < size - 1)
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'C'
				&& str[i][j] != 'E' && str[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_occurence (char **str, t_utils *map)
{
	int i;
	int j;
	//t_utils map;

	//ft_map_init(&map);

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				map.player++;
			if (str[i][j] == 'E')
				map.exit++;
			if (str[i][j] == 'C')
				map.collectible++;
			j++;
		}
		i++;
	}
	if (map.player !=1 || map.exit != 1 || map.collectible == 0)
		return(0);
	return (1);
}



