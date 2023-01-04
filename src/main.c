/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/04 10:24:34 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"


int main(int ac, char **av)
{
    t_vars  var;
    int height;

    height = ft_column(av[1]) * 200;

    if (ac != 2)
        return(0);
    else
    {
        var.mlx = mlx_init();
        var.map = ft_read_map(av[1]);
        ft_check_map(var.map, av[1]);
        var.win = mlx_new_window(var.mlx, (ft_line(av[1]) *64), height, "Hello");
        ft_put_map(var);
        var.max_collec = ft_all_collectible(var.map);
        mlx_hook(var.win, KeyPress, KeyPressMask, ft_key_hook, &var);
        mlx_hook(var.win, ClientMessage, LeaveWindowMask, ft_mouse_hook, &var);
        mlx_loop(var.mlx);
        return(0);
    }

}
