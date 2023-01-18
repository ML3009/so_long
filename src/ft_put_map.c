/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:41:25 by ml                #+#    #+#             */
/*   Updated: 2023/01/18 08:13:16 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_put_image(t_vars *var)
{
    var->img_player = mlx_xpm_file_to_image(var->mlx, "./sprites/player.xpm", &var->width, &var->height);
    if (!var->img_player)
        ft_close_img(var);
    var->img_collectible = mlx_xpm_file_to_image(var->mlx, "./sprites/collectible.xpm", &var->width, &var->height);
    if (!var->img_collectible)
        ft_close_img(var);
    var->img_background = mlx_xpm_file_to_image(var->mlx, "./sprites/background.xpm", &var->width, &var->height);
    if (!var->img_background)
        ft_close_img(var);
    var->img_wall = mlx_xpm_file_to_image(var->mlx, "./sprites/wall.xpm", &var->width, &var->height);
    if (!var->img_wall)
         ft_close_img(var);
    var->img_exit = mlx_xpm_file_to_image(var->mlx, "./sprites/exit.xpm", &var->width, &var->height);
    if (!var->img_exit)
        ft_close_img(var);
}

void    ft_put_map(t_vars *var)
{
    int x;
    int y;

    ft_put_image(var);
    y = 0;
    while(var->map[y])
    {
        x = 0;
        while(var->map[y][x])
        {
            if(var->map[y][x] == 'P')
                mlx_put_image_to_window(var->mlx, var->win, var->img_player, x * 32, y * 32);
            else if (var->map[y][x] == 'C')
                mlx_put_image_to_window(var->mlx, var->win, var->img_collectible, x * 32, y * 32);
            else if (var->map[y][x] == '0')
                mlx_put_image_to_window(var->mlx, var->win, var->img_background, x * 32, y * 32);
            else if (var->map[y][x] == '1')
                mlx_put_image_to_window(var->mlx, var->win, var->img_wall, x * 32, y * 32);
            else if (var->map[y][x] == 'E')
                mlx_put_image_to_window(var->mlx, var->win, var->img_exit, x * 32, y * 32);
            x++;
        }
        y++;
    }
}

