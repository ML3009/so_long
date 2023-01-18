/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:53:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 16:14:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// mlx_ptr, win_ptr, int x, int y, int color, char *string)

void	ft_put_string(t_vars *var)
{
	

	mlx_string_put(var->mlx, var->win, x, y, color, "phrase");


}

while (var->moves_count <= var->collectible)
{
	ft_printf("Total movement: %d\n", var->moves_count);
}




