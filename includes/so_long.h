/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:13:08 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/29 14:38:24 by mvautrot         ###   ########.fr       */
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
}  t_vars;

typedef struct s_data {
	void	*img;
	char	*relative_paths;
   void  *perso;
   void  *collec;
   void  *escape;
	int	img_widht;
	int	img_height;
}	t_data;

int   ft_check_ber(char *fd);
void   ft_map_init(t_map *map);
int   ft_line(char *str);
int   ft_column(char *str);
int   ft_check_size(char **str);
int   ft_check_wall(char **str, char *map);
int   ft_check_parsing(char **str);
int   ft_check_occurence (char **str);
int   ft_check_map(char **str, char *map);
void  ft_free_tab(char **tab);

#endif
