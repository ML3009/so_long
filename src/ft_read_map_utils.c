/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:41:25 by ml                #+#    #+#             */
/*   Updated: 2022/12/31 13:22:05 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_put_player(t_vars var, int x, int y)
{
    t_data  img;
    int width;
    int height;

    img.img = mlx_xpm_file_to_image(var.mlx, "./sprites/player.xpm", &width, &height);
    if(!img.img)
    {
        ft_free_tab(var.map);
        return;//a modifier
    }
    mlx_put_image_to_window(var.mlx, var.win, img.img, x * 50, y * 50);
}

void ft_put_collectible(t_vars var, int x, int y)
{
    t_data  img;
    int width;
    int height;

    img.img = mlx_xpm_file_to_image(var.mlx, "./sprites/collectible.xpm", &width, &height);
    if (!img.img)
    {
        ft_free_tab(var.map);
        return;
    }
    mlx_put_image_to_window(var.mlx, var.win, img.img, x * 50, y * 50);
}

void    ft_put_background(t_vars var, int x, int y)
{
    t_data img;
    int width;
    int height;

    img.img = mlx_xpm_file_to_image(var.mlx, "./sprites/background.xpm", &width, &height);
    if(!img.img)
    {
        ft_free_tab(var.map);
        return;
    }
    mlx_put_image_to_window(var.mlx, var.win, img.img, x * 50, y * 50);
}

void    ft_put_wall(t_vars var, int x, int y)
{
    t_data  img;
    int width;
    int height;

    img.img = mlx_xpm_file_to_image(var.mlx, "./sprites/wall.xpm", &width, &height);
    if(!img.img)
    {
        ft_free_tab(var.map);
        return;
    }
    mlx_put_image_to_window(var.mlx, var.win, img.img, x * 50, y * 50);
}

void    ft_put_exit(t_vars var, int x, int y)
{
    t_data  img;
    int width;
    int height;
    
    img.img = mlx_xpm_file_to_image(var.mlx, "./sprites/exit.xpm", &width, &height);
    if(!img.img)
    {
        ft_free_tab(var.map);
        return;
    }
    mlx_put_image_to_window(var.mlx, var.win, img.img, x * 50, y * 50);
}