/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:19:10 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 16:36:59 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void ft_index_player(int *x, int *y, char **str)
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
				(*x) = i;
				(*y) = j;
			}
			j++;
		}
		i++;
	}
}

void ft_up(t_vars var, int x, int y)
{
	var->map[x][y] == '0';
	var->map[x][y - 1] == 'P';
	var->moves_count++;
	ft_put_map((*var));
}

void ft_down(t_vars, int x, int y)
{
	var->map[x][y] == '0';
	var->map[x][y + 1] == 'P';
	var->moves_count++;
	ft_put_map((*var));
}

void ft_right(t_vars var, int x, int y)
{
	var->map[x][y] == '0';
	var->map[x - 1][y] == 'P';
	var->moves_count++;
	ft_put_map((*var));
}

void ft_left(t_vars var, int x, int y)
{
	var->map[x][y] == '0';
	var->map[x + 1][y] == 'P';
	var->moves_count++;
	ft_put_map((*var));
}
