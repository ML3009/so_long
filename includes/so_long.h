/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:13:08 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:36:41 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "libft.h"

typedef struct s_map
 {
    int player;
    int collectible;
    int exit;
 } t_map;

typedef struct s_vars
{
   void  *mlx;
   void  *win;
   char  **map;
}  t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
   int   bits_per_pixel;
   int   line_length;
   int   endian;
}	t_data;

//CHECK MAP

int   ft_check_ber(char *fd);
int   ft_check_size(char **str);
int   ft_check_wall(char **str, char *map);
int   ft_check_parsing(char **str);
int   ft_check_occurence (char **str);
int   ft_check_map(char **str, char *map);

//INITIALIZE READ AND PUT MAP

void   ft_map_init(t_map *map);
char  **ft_read_map(char *str);
void  ft_put_map(t_vars var);
void  ft_put_player(t_vars, int x, int y);

//UTILS

int   ft_line(char *str);
int   ft_column(char *str);
void  ft_free_tab(char **tab);

#endif
