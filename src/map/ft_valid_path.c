/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:57:00 by ml                #+#    #+#             */
/*   Updated: 2023/01/10 10:48:14 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

char	**ft_copy_map(char **str)
{
	int	i;
	char **copy;

	i = 0;
	while(str[i])
		i++;
	copy = malloc(i * sizeof(char *));
	if (!copy)
		return(NULL);
	i = 0;
	while(str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = NULL;
	return(copy);
}

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


void	ft_check_player(char **str, t_path *p)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == 'P')
			{
				p->player_x = j;
				p->player_y = i;
				return;
			}
			j++;
		}
		i++;
	}
}


void	ft_check_all_way(char **copy, t_path *p)
{
	copy[p->player_y][p->player_x] = 'P';

	if((copy[p->player_y + 1][p->player_x] == '0') && (copy[p->player_y + 1][p->player_x] == 'C'))
		ft_check_all_way(copy, p);
	if ((copy[p->player_y  - 1][p->player_x] == '0') && (copy[p->player_y - 1][p->player_x] == 'C'))
		ft_check_all_way(copy, p);
	if ((copy[p->player_y ][p->player_x + 1] == '0') && (copy[p->player_y][p->player_x + 1] == 'C'))
		ft_check_all_way(copy, p);
	if((copy[p->player_y ][p->player_x - 1] == '0') && (copy[p->player_y][p->player_x - 1] == 'C'))
		ft_check_all_way(copy, p);
}

/*pos = x y
if x - 1 y == P --> ok
else if x +1 y == P --> ok
else if x y -1 == P --> ok
else if x y + 1 == p --> ok
else
no */
