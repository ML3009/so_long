/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:38:29 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/28 15:45:48 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_aff_map(char **str, char *map)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "UNE FENETRE");

	mlx_loop(mlx);
}

