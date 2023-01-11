/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 19:08:15 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"


int main(int ac, char **av)
{
    t_vars  var;
    t_path p;

    ft_var_init(&var);

    if (ac != 2)
        return(0);
    else
    {
        ft_check_ber(av[1]);
        var.map = ft_read_map(av[1]);
        var.map_copy = ft_read_map(av[1]);
        var.line = ft_line(av[1]);
        var.column = ft_column(av[1]);
        ft_check_map(&var, av[1]);
        ft_check_path(var.map_copy, &p, &var);
        var.mlx = mlx_init();
        var.win = mlx_new_window(var.mlx, var.column * 32, var.line * 32, "Hello");
        ft_put_map(&var);
        mlx_hook(var.win, KeyPress, KeyPressMask, ft_key_hook, &var);
        mlx_hook(var.win, ClientMessage, LeaveWindowMask, ft_mouse_hook, &var);
        mlx_loop(var.mlx);
        ft_all_destroy(&var);
        return(0);
    }

}
