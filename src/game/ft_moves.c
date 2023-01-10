/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/10 11:31:19 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

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

int	ft_move_up(t_vars *var)
{
	int	y;
	int	x;


	ft_index_player(&y, &x, var->map);
	ft_printf("collect : %d ",var->collec_count);
	if (var->map[y - 1][x] == 'E' && var->collec_count == var->max_collec)
		ft_close_map(var);
	if (var->map[y - 1][x] != '1' && var->map[y - 1][x] != 'C' && var->map[y - 1][x] != 'E')
		ft_up(var, y, x);
	if (var->map [y - 1][x] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y - 1][x] = 'P';
		var->moves_count++;
		var->collec_count++;
		ft_put_map((*var));
		return(1);
	}
	return (0);
}

int ft_move_down(t_vars *var)
{
	int	y;
	int	x;

	ft_index_player(&y, &x, var->map);
	ft_printf("collect : %d ",var->collec_count);
	if (var->map[y + 1][x] == 'E' && var->collec_count == var->max_collec)
		ft_close_map(var);
	if(var->map[y + 1][x] != '1' && var->map[y + 1][x] != 'C' && var->map[y + 1][x] != 'E')
		ft_down(var, y, x);
	if (var->map[y + 1][x] =='C')
	{
		var->map[y][x] = '0';
		var->map[y + 1][x] = 'P';
		var->moves_count++;
		var->collec_count++;
		ft_put_map((*var));
		return(1);
	}
	return (0);
}

int ft_move_right(t_vars *var)
{
	int	y;
	int	x;

	ft_index_player(&y, &x, var->map);
	ft_printf("collect : %d ",var->collec_count);
	if (var->map[y][x + 1] == 'E' && var->collec_count == var->max_collec)
		ft_close_map(var);
	if(var->map[y][x + 1] != '1' && var->map[y][x + 1] != 'C' && var->map[y][x + 1] != 'E')
		ft_right(var, y, x);
	if(var->map[y][x + 1] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y][x + 1] = 'P';
		var->moves_count++;
		var->collec_count++;
		ft_put_map((*var));
		return(1);
	}
	return (0);
}

int ft_move_left(t_vars *var)
{
	int	y;
	int	x;


	ft_index_player(&y, &x, var->map);
	ft_printf("collect : %d ",var->collec_count);
	if(var->map[y][x - 1] == 'E' && var->collec_count == var->max_collec)
		ft_close_map(var);
	if(var->map[y][x - 1] != '1' && var->map[y][x - 1] != 'C' && var->map[y][x - 1] != 'E')
		ft_left(var, y, x);
	if(var->map[y][x - 1] == 'C')
	{
		var->map[y][x] = '0';
		var->map[y][x - 1] = 'P';
		var->moves_count++;
		var->collec_count++;
		ft_put_map((*var));
		return(1);
	}
	return (0);
}
