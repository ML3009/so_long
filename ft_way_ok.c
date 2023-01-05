/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:17:59 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/04 16:20:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index_CEP(int *y, int *x, char **str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P' || str[i][j] == 'C' || str[i][j] == 'E')
			{
				(*y) = i;
				(*x) = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_way(char **str)
{
	int	y;
	int	x;

	ft_index_CEP(&y, &x, str);
	
	if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
		&& str[i][j - 1] == '1' && str[i][j + 1] == '1' && str[i][j] == 'C')
			return(0);
	else if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
		&& str[i][j - 1] == '1' && str[i][j + 1] == '1' && str[i][j] == 'E')
			return(0);
	else if (str[i - j][x] == '1' && str[i + 1][j] == '1'
		&& str[i][j - 1] == '1' && str[i][j + 1] == '1' && str[i][j] == 'P')
		return(0);
	return(1);
}

/*int	ft_way_ok(char **str)
{
	int y;
	int x;

	y = 0;
	//ft_index_player(&y, &x, var->map);
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y - 1][x] == '1' && str[y + 1] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'C')
			return(0);
			else if (str[y - 1][x] == '1' && str[y + 1] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'E')
			return(0);
			else if (str[y - 1][x] == '1' && str[y + 1] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'P')
		}
	}
	return (1);
}*/


/*int	ft_way_ok(char **str)
{
	int y;
	int x;

	ft_index_player(&y, &x, str);
	if (var->map[y - 1][x] == '1' && var->map[y + 1][x] == '1'&& var->map[y][x - 1] == '1' && var->map[y][x + 1] == '1')
	{
		ft_putstr_fd("Error\nProblem with the way", 2);
		ft_close_map(var);
		return(0);
	}
	return(1);
}
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y - 1][x] == '1' && str[y + 1][x] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'C')
				{
					ft_putstr_fd("Error\nProblem with the way", 2);
					ft_free_tab(str);
					return(0);
				}
			if (str[y - 1][x] == '1' && str[y + 1][x] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'E')
				{
					ft_putstr_fd("Error\nProblem with the way", 2);
					ft_free_tab(str);
					return(0);
				}
			if (str[y - 1][x] == '1' && str[y + 1][x] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'P')
				{
					ft_putstr_fd("Error\nProblem with the way", 2);
					ft_free_tab(str);
					return(0);
				}
			x++;
		}
		y++;
	}*/
	/*if (ft_way_ok(str) == 0)
	{
		ft_putstr_fd("Error\nProblem with the way", 2);
		ft_free_tab(str);
        return(0);
	}

	return (1);
}*/

