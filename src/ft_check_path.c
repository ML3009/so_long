/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:57:00 by ml                #+#    #+#             */
/*   Updated: 2023/01/11 14:58:07 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	ft_check_exit(char **str, t_path *p)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == 'E')
			{
				p->exit_x = j;
				p->exit_y = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_all_way(char **copy,  int i, int j, t_vars *var)
{
	if (copy[i][j] == 'C')
		var->collectable++;
	copy[i][j] = 'P';
	if((copy[i + 1][j] != '1') && (copy[i + 1][j] != 'E') && copy[i + 1][j]!= 'P')
		ft_check_all_way(copy, i + 1, j, var);
	if ((copy[i ][j + 1] != '1') && (copy[i][j + 1] != 'E') && copy[i][j + 1] != 'P')
		ft_check_all_way(copy, i, j + 1, var);
	if ((copy[i  - 1][j] != '1') && (copy[i - 1][j] != 'E') &&(copy[i - 1][j] != 'P'))
		ft_check_all_way(copy, i - 1, j, var);
	if((copy[i][j- 1] != '1') && (copy[i][j - 1] != 'E') && (copy[i][j - 1] != 'P'))
		ft_check_all_way(copy, i, j - 1, var);
}

int	ft_good_path(char **copy, t_path *p, t_vars *var)
{
	if ((copy[p->exit_y + 1][p->exit_x] == 'P' || copy[p->exit_y - 1][p->exit_x] == 'P'
		|| copy[p->exit_y][p->exit_x + 1] == 'P' || copy[p->exit_y][p->exit_x - 1] == 'P')
			&& (var->collectable == var->max_collec))
		return(1);
	return(0);
}

void	ft_check_path(char **map_copy, t_path *p, t_vars *var)
{
	int i;
	int	j;
	ft_index_player(&i, &j, map_copy);
	ft_check_exit(map_copy, p);
	ft_check_all_way(map_copy, i, j, var);
	if(ft_good_path(map_copy, p, var) == 0)
	{
		ft_putstr_fd("Error\nWrong way\n", 2);
		ft_free_tab(map_copy);
		exit(1);
	}
}
