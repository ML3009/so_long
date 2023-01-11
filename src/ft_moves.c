/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:49:05 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 19:49:14 by ml               ###   ########.fr       */
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


int	ft_move_up(t_vars *var)
{
	int	y;
	int	x;

	ft_index_player(&y, &x, var->map);
	if (var->map[y - 1][x] == 'E' && var->collec_count == var->collectible)
		ft_close_map(var);
	if (var->map[y - 1][x] != '1' && var->map[y - 1][x] != 'E')
	{
		if (var->map[y - 1][x] == 'C')
			var->collec_count++;
		var->map[y][x] = '0';
		var->map[y - 1][x] = 'P';
		var->moves_count++;
		ft_printf("Total movement: %d\n",var->moves_count);
		ft_put_map(var);
		return(1);
	}
	return (0);
}

int ft_move_down(t_vars *var)
{
	int	y;
	int	x;

	ft_index_player(&y, &x, var->map);
	if (var->map[y + 1][x] == 'E' && var->collec_count == var->collectible)
		ft_close_map(var);
	if(var->map[y + 1][x] != '1' && var->map[y + 1][x] != 'E')
	{
		if (var->map[y + 1][x] == 'C')
			var->collec_count++;
		var->map[y][x] = '0';
		var->map[y + 1][x] = 'P';
		var->moves_count++;
		ft_printf("Total movement: %d\n",var->moves_count);
		ft_put_map(var);
		return(1);
	}
	return (0);
}

int ft_move_right(t_vars *var)
{
	int	y;
	int	x;

	ft_index_player(&y, &x, var->map);
	if (var->map[y][x + 1] == 'E' && var->collec_count == var->collectible)
		ft_close_map(var);
	if(var->map[y][x + 1] != '1' && var->map[y][x + 1] != 'E')
	{
		if (var->map[y][x + 1] == 'C')
			var->collec_count++;
		var->map[y][x] = '0';
		var->map[y][x + 1] = 'P';
		var->moves_count++;
		
		ft_printf("Total movement: %d\n",var->moves_count);
		ft_put_map(var);
		return(1);
	}
	return (0);
}

int ft_move_left(t_vars *var)
{
	int	y;
	int	x;
	
	ft_index_player(&y, &x, var->map);

	if(var->map[y][x - 1] == 'E' && var->collec_count == var->collectible)
		ft_close_map(var);
	if(var->map[y][x - 1] != '1' && var->map[y][x - 1] != 'E')
	{
		if (var->map[y][x - 1] == 'C')
			var->collec_count++;
		var->map[y][x] = '0';
		var->map[y][x - 1] = 'P';
		var->moves_count++;
		ft_printf("Total movement: %d\n",var->moves_count);
		ft_put_map(var);
		return(1);
	}
	return (0);
}
