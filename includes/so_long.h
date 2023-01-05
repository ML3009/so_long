/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:13:08 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/05 17:03:33 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../lib_dil/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_utils
 {
   int player;
   int collectible;
   int exit;
 } t_utils;

typedef struct s_graph
{
  char **visit;
  int c_max;
  int exit;
} t_graph;


typedef struct s_vars
{
   void  *mlx;
   void  *win;
   char  **map;
   int   moves;
   int   moves_count;
   int   collec_count;
   int   max_collec;
}  t_vars;

typedef struct s_data
{
	void	*img;
}	t_data;

//CHECK MAP

int   ft_check_ber(char *fd);
int   ft_check_size(char **str);
int   ft_check_wall(char **str, char *map);
int   ft_check_parsing(char **str);
int   ft_check_occurence (char **str);
int   ft_check_map(char **str, char *map);
void   **ft_copy(char **str, char *map);
void    ft_copy_init(t_graph *copy);
int	ft_check_all_way(char **str, t_graph *copy, int i, int j);
//int   ft_check_way(char **str);
//void  ft_check_all_way(t_vars *var, t_graph *copy);



//INITIALIZE READ AND PUT MAP

void   ft_map_init(t_utils *map);
char  **ft_read_map(char *str);
void  ft_put_map(t_vars var);
void  ft_put_player(t_vars, int x, int y);
void  ft_put_collectible(t_vars, int x, int y);
void  ft_put_background(t_vars var, int x, int y);
void  ft_put_wall(t_vars var, int x, int y);
void  ft_put_exit(t_vars var, int x, int y);


//UTILS

int   ft_line(char *str);
int   ft_column(char *str);
void  ft_free_tab(char **tab);
void  ft_close_map(t_vars *var);
int   ft_all_collectible(char **str);

//MOVES PLAYER

void  ft_index_player(int *y, int *x, char **str);
void  ft_up(t_vars *var, int y, int x);
void  ft_down(t_vars *var, int y, int x);
void  ft_right(t_vars *var, int y, int x);
void  ft_left(t_vars *var, int y, int x);
int   ft_move_up(t_vars *var);
int   ft_move_down(t_vars *var);
int   ft_move_right(t_vars *var);
int   ft_move_left(t_vars *var);

//KEY HOOK

int   ft_key_hook(int keycode, t_vars *var);
int   ft_mouse_hook(t_vars *var);

#endif
