/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:00:15 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 08:22:06 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "UNE FENETRE");
	
	mlx_loop(mlx);
}




/*int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}*/
