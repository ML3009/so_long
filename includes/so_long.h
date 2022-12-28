/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:13:08 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/27 09:52:49 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "libft.h"

typedef struct s_map
 {
    int i;
    int j;
    int x;
    int y;
 } t_map;
 
void  ft_init_shifting(t_map *va);
char  ft_init_map(char **map)
void  ft_destroy_map(char **map);
int	ft_check_name(char *fd);
int   ft_check_parsing(char *map_str);
void  ft_count_occurence(int *count_c, int *count_e, int *count_p, char c);
int   ft_check_occurence(char **map);

 

 





#endif
