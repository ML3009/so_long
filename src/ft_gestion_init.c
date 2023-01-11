/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:02:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 15:02:19 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_map_init(t_utils *map)
{

    map->player = 0;
    map->collectible = 0;
    map->exit = 0;
}

void    ft_var_init(t_vars *var)
{

    var->collec_count = 0;
    var->collectable = 0;
    var->line = 0;
    var->column = 0;
}
