/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:41:25 by ml                #+#    #+#             */
/*   Updated: 2023/01/23 12:09:37 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_image(t_vars *var)
{
	var->img_p = mlx_xpm_file_to_image(var->mlx, "./sprites/player.xpm", \
		&var->width, &var->height);
	if (!var->img_p)
		ft_close_img(var);
	var->img_c = mlx_xpm_file_to_image(var->mlx, "./sprites/collectible.xpm", \
		&var->width, &var->height);
	if (!var->img_c)
		ft_close_img(var);
	var->img_b = mlx_xpm_file_to_image(var->mlx, "./sprites/background.xpm", \
		&var->width, &var->height);
	if (!var->img_b)
		ft_close_img(var);
	var->img_w = mlx_xpm_file_to_image(var->mlx, "./sprites/wall.xpm", \
		&var->width, &var->height);
	if (!var->img_w)
		ft_close_img(var);
	var->img_e = mlx_xpm_file_to_image(var->mlx, "./sprites/exit.xpm", \
		&var->width, &var->height);
	if (!var->img_e)
		ft_close_img(var);
}

void	ft_put_map(t_vars *var)
{
	int	x;
	int	y;

	y = -1;
	while (var->map[++y])
	{
		x = -1;
		while (var->map[y][++x])
		{
			if (var->map[y][x] == 'P')
				mlx_put_image_to_window(var->mlx, var->win, var->img_p, \
					x * 32, y * 32);
			else if (var->map[y][x] == 'C')
				mlx_put_image_to_window(var->mlx, var->win, var->img_c, \
					x * 32, y * 32);
			else if (var->map[y][x] == '0')
				mlx_put_image_to_window(var->mlx, var->win, var->img_b, \
					x * 32, y * 32);
		}
	}
	ft_put_map2(var);
}

void	ft_put_map2(t_vars *var)
{
	int	x;
	int	y;

	y = -1;
	while (var->map[++y])
	{
		x = -1;
		while (var->map[y][++x])
		{
			if (var->map[y][x] == '1')
				mlx_put_image_to_window(var->mlx, var->win, var->img_w, \
					x * 32, y * 32);
			else if (var->map[y][x] == 'E')
				mlx_put_image_to_window(var->mlx, var->win, var->img_e, \
					x * 32, y * 32);
		}
	}
	ft_put_string(var);
}
