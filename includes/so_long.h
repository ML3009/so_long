/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:48:35 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 11:16:15 by mvautrot         ###   ########.fr       */
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

 typedef struct s_path
{
	int   player_x;
  int   player_y;
  int		exit_x;
	int		exit_y;
  int way;
}	t_path;



typedef struct s_vars
{
   void  *mlx;
   void  *win;
   char  **map;
   char  **map_copy;
   //int  line;
  // int  column;
   int   moves;
   int   moves_count;
   int   collectable;
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
char   **ft_copy(char **str);
void  ft_check_exit(char **str, t_path *p);
void  ft_check_player(char **str, t_path *p);
//void	ft_check_all_way(char **copy, t_path *p);
int  ft_good_path(char **copy, t_path *p, t_vars *var);
void  ft_check_path(char **copy, t_path *p, t_vars *var);
void    ft_var_init(t_vars *var);
void	ft_check_all_way(char **copy, int i, int j, t_vars *var);





//INITIALIZE READ AND PUT MAP

void   ft_map_init(t_utils *map);
char  **ft_read_map(char *str);
void  ft_put_map(t_vars *var);
void  ft_put_player(t_vars *vat, int x, int y);
void  ft_put_collectible(t_vars *var, int x, int y);
void  ft_put_background(t_vars *var, int x, int y);
void  ft_put_wall(t_vars *var, int x, int y);
void  ft_put_exit(t_vars *var, int x, int y);


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


/* test */
void printmap(char **map_copy);
#endif
