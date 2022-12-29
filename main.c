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


typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}	t_data;


void	my_mlx_pixel_put (t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*) dst = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	x;
	int	y;
	int color;

	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	x = 0;
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
	while(x < 1000)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
	}

	x= 999;
	y = 0;
	while(y < 1000)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y++;
	}


	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

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
