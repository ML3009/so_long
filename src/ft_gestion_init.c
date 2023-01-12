/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:02:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/12 10:49:37 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    mlx_initialisation(t_vars *var)
{
    var->mlx = mlx_init();
    if(var->mlx == NULL)
        exit(1);
        //msg erreur
    var->win = mlx_new_window(var->mlx, var->column * 32, var->line * 32, "MiLlEdUnE");
    if (var->win == NULL)
    {
        free(var->win);
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
