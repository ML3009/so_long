/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestion_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:02:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 19:14:48 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_var_init(t_vars *var)
{

    var->line = 0;
    var->column = 0;
    var->player = 0;
    var->exit = 0;
    var->collectible = 0;
    var->collec_count = 0;
    var->collectable = 0;
    var->moves_count = 0;
}
