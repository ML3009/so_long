/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:35:55 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 14:58:35 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    ft_put_map(t_vars *var)
{
    int i;
    int j;

    i = 0;
    while(var->map[i])
    {
        j = 0;
        while(var->map[i][j])
        {
            if(var->map[i][j] == 'P')
                 ft_put_player(var, j, i);
            else if (var->map[i][j] == 'C')
                 ft_put_collectible(var, j, i);
            else if (var->map[i][j] == '0')
                 ft_put_background(var, j, i);
            else if (var->map[i][j] == '1')
                 ft_put_wall(var, j, i);
            else if (var->map[i][j] == 'E')
                 ft_put_exit(var, j, i);
            j++;
        }
        i++;
    }
}
