/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maindino.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:17:03 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/29 14:04:49 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct s_var {
	void	*mlx;
	void	*win;
}	t_vars;


int	main(void)
{
	void	*img;
	char	*relative_path = "player.xpm";
	int		img_width;
	int		img_height;
	t_vars	vars;



	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);

	mlx_loop(vars.mlx);
}
