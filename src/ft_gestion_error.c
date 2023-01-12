/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:48 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/12 11:17:10 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void ft_close_map(t_vars *var)
{
    ft_free_tab(var->map);
    mlx_destroy_window(var->mlx, var->win);
    exit(0);
}

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

void   ft_all_destroy(t_vars *var)
{
    free(var->map);
    mlx_destroy_image(var->mlx, var->img.img_player);
    mlx_destroy_image(var->mlx, var->img.img_collectible);
    mlx_destroy_image(var->mlx, var->img.img_wall);
    mlx_destroy_image(var->mlx, var->img.img_background);
    mlx_destroy_image(var->mlx, var->img.img_exit);
    mlx_destroy_window(var->mlx, var->win);
    mlx_destroy_display(var->mlx);
    free(var->mlx);
}
