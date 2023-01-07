/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:57:00 by ml                #+#    #+#             */
/*   Updated: 2023/01/06 17:32:33 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

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
			if (map[i][j] == 'E')
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


void	ft_check_all_way(char **copy, int i, int j)
{
	copy[i][j] = 'P';

	if((copy[i + 1][j] == '0') && (copy[i + 1][j] == 'C'))
		ft_check_all_way(copy, i + 1, j);
	if ((copy[i - 1][j] == '0') && (copy[i - 1][j] == 'C'))
		ft_check_all_way(copy, i - 1, j);
	if ((copy[i][j + 1] == '0') && (copy[i][j + 1] == 'C'))
		ft_check_all_way(copy, i, j + 1);
	if((copy[i][j - 1] == '0') && (copy[i][j - 1] == 'C'))
		ft_check_all_way(copy, i, j - 1);
	return;
}

void ft_good_way(char **str, t_vars *var, t_path *p)
{
    int i;
    int j;
	
	i = 0;
	j = 0;
	if (str[p->exit_y + 1][p->exit_x]!= 'P' &&
			str[p->exit_y - 1][p->exit_x] != 'P' &&
			str[p->exit_y][p->exit_x + 1] != 'P' &&
			str[p->exit_y][p->exit_x - 1] != 'P')
		free_path(all, p, str);
	
}

ft_check_path(char **str, t_vars *var)
{
    char **copy;

    copy = ft_copy_map(str);
    ft_index_player(&i, &j, str);

}