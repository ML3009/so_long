/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:00:15 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/29 09:43:25 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*relative_paths; 
	int	img_widht;
	int	img_height;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}	t_data;

typedef struct s_var {
	void	*mlx;
	void	*win;
}	t_vars;


void	my_mlx_pixel_put (t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*) dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return(0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("You click but you don't have any shutdown of this program!\n");
	return(0);
}


int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}




int	main(void)
{
	//void	*mlx;
	//void	*mlx_win;
	//int	x;
	//int	y;
	//int color;

	//t_data	img;
	t_data	img;
	t_vars	vars;

	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.relative_paths, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	img.relative_paths = "./dino.xpm";
	img.img = mlx_xpm_file_to_image(vars.mlx, img.relative_paths, &img.img_widht, &img.img_height);


	/*x = 0;
	y = 0;
	color = 0x0033FF33;
	while(x < 1000 && y < 1000)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
		y++;
	}

	x = 0;
	y = 0;
	color = 0x003300FF;
	while(x < 1000)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}

	x= 999;
	y = 0;
	color = 0x00FF3300;
	while(y < 1000)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y++;
	}*/


	mlx_put_image_to_window(vars.mlx, vars.win, img.relative_paths, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);

}


/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "UNE FENETRE");

	mlx_loop(mlx);
}*/




/*int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}*/
