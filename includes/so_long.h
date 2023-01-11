/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:48:35 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 19:49:42 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../lib_dil/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

 typedef struct s_path
{
  int		exit_x;
	int		exit_y;
}	t_path;

typedef struct s_data
{
	void	*img_player;
  void  *img_collectible;
  void  *img_exit;
  void  *img_wall;
  void  *img_background;
}	t_data;

typedef struct s_vars
{
   void  *mlx;
   void  *win;
   char  **map;
   char  **map_copy;
   int   line;
   int   column;
   int   player;
   int   exit;
   int   collectible;
   int   collec_count;
   int   collectable;
   int   moves_count;
   t_path *p;
   t_data img;
}  t_vars;



//CHECK MAP

int   ft_check_ber(char *fd);
int   ft_check_size(t_vars *var);
int   ft_check_wall(t_vars *var, char *map);
int   ft_check_parsing(t_vars *var);
int   ft_check_occurence (t_vars *var);
int   ft_check_map(t_vars *var, char *str);
char   **ft_copy(char **str);
void  ft_check_exit(char **str, t_path *p);
void  ft_check_player(char **str, t_path *p);
int  ft_good_path(char **copy, t_path *p, t_vars *var);
void  ft_check_path(char **copy, t_path *p, t_vars *var);
void    ft_var_init(t_vars *var);
void	ft_check_all_way(char **copy, int i, int j, t_vars *var);





//INITIALIZE READ AND PUT MAP

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
void   ft_all_destroy(t_vars *var);

//MOVES PLAYER

void  ft_index_player(int *y, int *x, char **str);
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
