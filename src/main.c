/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 08:25:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"


int main(int ac, char **av)
{
    t_vars  var;
    t_path p;
    int height;

    ft_var_init(&var);

    height = ft_column(av[1]) * 200;

    if (ac != 2)
        return(0);
    else
    {
        var.mlx = mlx_init();
        ft_check_ber(av[1]);
        var.map = ft_read_map(av[1]);
        var.map_copy = ft_read_map(av[1]);
        var.max_collec = ft_all_collectible(var.map);
        ft_check_path(var.map_copy, &p, &var);
        ft_check_map(var.map, av[1]);
        var.win = mlx_new_window(var.mlx, (ft_line(av[1]) *64), height, "Hello");
        ft_put_map(var);
        mlx_hook(var.win, KeyPress, KeyPressMask, ft_key_hook, &var);
        mlx_hook(var.win, ClientMessage, LeaveWindowMask, ft_mouse_hook, &var);
        mlx_loop(var.mlx);
        return(0);
    }

}
