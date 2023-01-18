/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:30:09 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 14:32:01 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_mouse_hook(t_vars *var)
{
	ft_close_nap(var);
	return (0);
}

int	ft_key_hook(int keycode, t_vars *var)
{
	static int	count_key;

	if (keycode == XK_Escape)
		ft_close_nap(var);
	if (keycode == XK_Up || keycode == XK_w)
		count_key += ft_move_up(var);
	if (keycode == XK_Down || keycode == XK_s)
		count_key += ft_move_down(var);
	if (keycode == XK_Right || keycode == XK_d)
		count_key += ft_move_right(var);
	if (keycode == XK_Left || keycode == XK_a)
		count_key += ft_move_left(var);
	return (0);
}
