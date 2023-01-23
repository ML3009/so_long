/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:53:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/23 13:47:49 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_string(t_vars *var)
{
	char	*convert_moves;
	int		i;
	int		j;

	j = (var->column * 32) / 2;
	i = (var-> line * 32);
	while (i < var->line * 32 + 40)
	{
		while (j < (var->column * 32))
		{
			mlx_pixel_put(var->mlx, var->win, j, i, 0x0000);
			j++;
		}
	i++;
	j = 0;
	}
	convert_moves = ft_itoa(var->moves_count);
	mlx_string_put(var->mlx, var->win, ((var->column * 32) / 2), \
	((var->line * 32) + 20), 0xFFFFFF, "MOVES: ");
	ft_printf("Moves: ");
	mlx_string_put(var->mlx, var->win, ((var->column * 32) / 2 + 50), \
	((var->line * 32) + 20), 0xFFFFFF, convert_moves);
	ft_printf("%s\n", convert_moves);
	free(convert_moves);
}
