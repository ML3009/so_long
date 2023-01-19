/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:53:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/19 16:26:22 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// mlx_ptr, win_ptr, int x, int y, int color, char *string)
void	ft_put_string(t_vars *var)
{
	char	*convert_moves;

	convert_moves = ft_itoa(var->moves_count);
	mlx_string_put(var->mlx, var->win, (var->line + 305) , (var->column + 160), 0xFFFFFF, "MOVES: ");
	ft_printf("Moves: ");
	mlx_string_put(var->mlx, var->win, (var->line + 375) , (var->column + 160), 0xFFFFFF, convert_moves);
	ft_printf("%s\n", convert_moves);
	free(convert_moves);
}




