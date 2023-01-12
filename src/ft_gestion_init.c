/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:02:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/12 13:56:29 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    mlx_initialisation(t_vars *var)
{
    var->mlx = mlx_init();
    if(var->mlx == NULL)
    {
        ft_free_tab(var->map);
        ft_putstr_fd("Error\nWrong initialisation\n", 2);
        exit(1);
    }
    var->win = mlx_new_window(var->mlx, var->column * 32, var->line * 32, "MiLlEdUnE");
    if (var->win == NULL)
    {
        free(var->map);
        ft_putstr_fd("Error\nWrong initialisation\n", 2);
        exit(1);
    }
}

void    ft_var_init(t_vars *var)
{
    var->line = 0;
    var->column = 0;
    var->height = 32;
    var->width = 32;
    var->player = 0;
    var->exit = 0;
    var->collectible = 0;
    var->collec_count = 0;
    var->collectable = 0;
    var->moves_count = 0;
}
