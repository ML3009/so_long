/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:38:28 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 16:47:34 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	ft_move_up(t_vars var, int x, int y)
{
	int	i;

	i = 0;
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
