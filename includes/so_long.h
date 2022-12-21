/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:13:08 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 16:58:23 by mvautrot         ###   ########.fr       */
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
 
 int	ft_check_name(char *fd);
 int    ft_check_cep(char **str);
 void   map_init(t_map *map);

 





#endif
