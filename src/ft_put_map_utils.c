/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:41:25 by ml                #+#    #+#             */
/*   Updated: 2023/01/11 20:01:35 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_put_player(t_vars *var, int x, int y)
{
     t_data  img;
     int width;
     int height;

    width = 0;
    height = 0;
     img.img_player = mlx_xpm_file_to_image(var->mlx, "./sprites/player.xpm", &width, &height);
     if(!img.img_player)
     {
        ft_free_tab(var->map);
        exit(1);
     }
     mlx_put_image_to_window(var->mlx, var->win, img.img_player, x * 32, y * 32);
}

void ft_put_collectible(t_vars *var, int x, int y)
{
     t_data  img;
     int width;
     int height;

     width = 0;
     height = 0;
     
     img.img_collectible = mlx_xpm_file_to_image(var->mlx, "./sprites/collectible.xpm", &width, &height);
     if (!img.img_collectible)
     {
         ft_free_tab(var->map);
         exit(1);
     }
     mlx_put_image_to_window(var->mlx, var->win, img.img_collectible, x * 32, y * 32);
 }

void    ft_put_background(t_vars *var, int x, int y)
{
    t_data img;
    int width;
    int height;

     width = 0;
     height = 0;
   
    img.img_background = mlx_xpm_file_to_image(var->mlx, "sprites/background.xpm", &width, &height);
    if(!img.img_background)
    {
        ft_free_tab(var->map);
        exit(1);
    }
    mlx_put_image_to_window(var->mlx, var->win, img.img_background, x * 32, y * 32);
}

 void    ft_put_wall(t_vars *var, int x, int y)
{
     t_data  img;
     int width;
     int height;

     width = 1;
     height = 1;

     img.img_wall = mlx_xpm_file_to_image(var->mlx, "./sprites/wall.xpm", &width, &height);
     if(!img.img_wall)
     {
         ft_free_tab(var->map);
         exit(1);
     }
     mlx_put_image_to_window(var->mlx, var->win, img.img_wall, x * 32, y * 32);
}

void    ft_put_exit(t_vars *var, int x, int y)
{
     t_data  img;
     int width;
     int height;

     width = 0;
     height = 0;

     img.img_exit = mlx_xpm_file_to_image(var->mlx, "./sprites/exit.xpm", &width, &height);
     if(!img.img_exit)
     {
         ft_free_tab(var->map);
         exit(1);
    }
     mlx_put_image_to_window(var->mlx, var->win, img.img_exit, x * 32, y * 32);
}
