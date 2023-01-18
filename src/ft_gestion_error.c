/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:48 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 08:13:37 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void   ft_close_map(t_vars *var)
{
    ft_printf("Total movement: %d\n",var->moves_count + 1);
    ft_free_tab(var->map);
    mlx_destroy_image(var->mlx, var->img_player);
    mlx_destroy_image(var->mlx, var->img_collectible);
    mlx_destroy_image(var->mlx, var->img_wall);
    mlx_destroy_image(var->mlx, var->img_background);
    mlx_destroy_image(var->mlx, var->img_exit);
    mlx_destroy_window(var->mlx, var->win);
    mlx_destroy_display(var->mlx);
    free(var->mlx);
    exit(0);
}

void   ft_close_nap(t_vars *var)
{
    ft_free_tab(var->map);
    mlx_destroy_image(var->mlx, var->img_player);
    mlx_destroy_image(var->mlx, var->img_collectible);
    mlx_destroy_image(var->mlx, var->img_wall);
    mlx_destroy_image(var->mlx, var->img_background);
    mlx_destroy_image(var->mlx, var->img_exit);
    mlx_destroy_window(var->mlx, var->win);
    mlx_destroy_display(var->mlx);
    free(var->mlx);
    exit(0);
}


void   ft_close_img(t_vars *var)
{
    ft_free_tab(var->map);
    if (var->img_player)
        mlx_destroy_image(var->mlx, var->img_player);
    if (var->img_collectible)
        mlx_destroy_image(var->mlx, var->img_collectible);
    if (var->img_background)
        mlx_destroy_image(var->mlx, var->img_background);
    if (var->img_wall)
        mlx_destroy_image(var->mlx, var->img_wall);
    if (var->img_exit)
        mlx_destroy_image(var->mlx, var->img_exit);
    mlx_destroy_window(var->mlx, var->win);
    mlx_destroy_display(var->mlx);
    free(var->mlx);
    ft_putstr_fd("Error\nWrong image\n", 2);
    exit(0);
}
