/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:19:10 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/04 08:20:41 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void ft_index_player(int *y, int *x, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				(*y) = i;
				(*x) = j;
			}
			j++;
		}
		i++;
	}
}

void ft_up(t_vars *var, int y, int x)
{

	var->map[y][x] = '0';
	var->map[y - 1][x] = 'P';
	var->moves_count++;
	ft_put_map((*var));
}

void ft_down(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y + 1][x] = 'P';
	var->moves_count++;
	ft_put_map((*var));
}

void ft_right(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y][x + 1] = 'P';
	var->moves_count++;
	ft_put_map((*var));
}

void ft_left(t_vars *var, int y, int x)
{
	var->map[y][x] = '0';
	var->map[y][x - 1] = 'P';
	var->moves_count++;
	ft_put_map((*var));
}
