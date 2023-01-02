/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 17:27:24 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	ft_move_up(t_vars var, int x, int y)
{
	ft_index_player(&x, &y, var->map);
	if (var->map[x][y - 1] != '1' && var->map[x][y - 1] != 'C' && var->map[x][y - 1] != 'E')
		ft_up(var, x, y);
	if (var->map [x][y - 1] == 'C')
	{
		var->map[x][y] = '0';
		var->map[x][y - 1] = 'P';
		var->moves_count++;
		ft_put_map((*var));
		return(1);
	}
	if (var->map[x][y - 1] == 'E' && var->/*le max de collectible alors il faut fermer*/)
		return (0);
}

int ft_move_down(t_vars var, int x, int y)
{
	ft_index_player(&x, &y, var->map);
	if(var->map[x][y + 1] != '1' && var->map[x][y + 1] != 'C' && var->map[x][y + 1] != 'E')
		ft_down(var, x, y);
	if (var->map[x][y + 1] =='C')
	{
		var->map[x][y] = '0'
		var->map[x][y + 1] = 'P';
		var->moves_count++;
		ft_put_map((*var));
		return(1);
	}
if (var->map[x][y + 1] == 'E' && var->/*le max de collectible alors il faut fermer*/)
		return (0);
	/*en gros la on sort et il faut fermer la fenetre*/
}

int ft_move_right(t_vars var, int x, int y)
{
	ft_index_player(&x, &y, var->map);
	if(var->map[x + 1][y] != '1' && var->map[x + 1][y] != 'C' && var->map[x + 1][y] != 'E')
		ft_right(var, x, y);
	if(var->map[x + 1][y] == 'C')
	{
		var->map[x][y] = '0';
		var->map[x + 1][y] = 'P';
		var->moves_count++;
		ft_put_map((*var));
		return(1);
	}
	if (var->map[x + 1][y] == 'E' && var->/*le max de collectible alors il faut fermer*/)
		return (0);
	/*en gros la on sort et il faut fermer la fenetre*/
}

int ft_move_left(t_vars var, int x, int y)
{
	ft_index_player(&x, &y, var->map);
	if(var->map[x - 1][y] != '1' && var->map[x - 1][y] != 'C' && var->map[x - 1][y] != 'E')
		ft_left(var, x, y);
	if(var->map[x - 1][y] == 'C')
	{
		var->map[x][y] = '0';
		var->map[x - 1][y] = 'P';
		var->moves_count++;
		ft_put_map((*var));
		return(1);
	if(var->map[x - 1][y] == 'E'/*le max de collectible alors il faut fermer*/)
		return (0);
	/*en gros la on sort et il faut fermer la fenetre*/
	}

}
