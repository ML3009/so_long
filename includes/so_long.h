/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:48:35 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/23 13:39:55 by mvautrot         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy;
	int		line;
	int		column;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collectible;
	int		player_x;
	int		player_y;
	int		collec_count;
	int		collectable;
	int		moves_count;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	void	*img_w;
	void	*img_b;
	void	*black;
	char	*print_moves;
	t_path	*p;
}	t_vars;

//CHECK MAP

int		ft_check_ber(char *fd);
int		ft_check_size(t_vars *var);
int		ft_check_wall(t_vars *var, char *map);
int		ft_check_parsing(t_vars *var);
int		ft_check_occurence(t_vars *var);
int		ft_check_map(t_vars *var, char *str);
int		ft_check_map2(t_vars *var);
char	**ft_copy(char **str);
void	ft_check_exit(char **str, t_path *p);
void	ft_check_player(char **str, t_path *p);
int		ft_good_path(char **copy, t_path *p, t_vars *var);
void	ft_check_path(char **copy, t_path *p, t_vars *var);
void	ft_var_init(t_vars *var);
void	ft_check_all_way(char **copy, int i, int j, t_vars *var);

//INITIALIZE READ AND PUT MAP

char	**ft_read_map(char *str);
void	ft_put_image(t_vars *var);
void	ft_put_map(t_vars *var);
void	ft_put_map2(t_vars *var);
void	ft_redraw_map(t_vars *var);
void	mlx_initialisation(t_vars *var);

//UTILS

int		ft_line(char *str);
int		ft_column(char *str);
void	ft_free_tab(char **tab);
void	ft_close_map(t_vars *var);
void	ft_close_nap(t_vars *var);
void	ft_close_img(t_vars *var);

//MOVES PLAYER

void	ft_index_player(int *y, int *x, char **str);
int		ft_move_up(t_vars *var);
int		ft_move_down(t_vars *var);
int		ft_move_right(t_vars *var);
int		ft_move_left(t_vars *var);

//KEY HOOK

int		ft_key_hook(int keycode, t_vars *var);
int		ft_mouse_hook(t_vars *var);

//BONUS

void	ft_put_string(t_vars *var);
#endif
