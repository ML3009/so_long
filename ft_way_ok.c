/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:17:59 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/06 16:49:04 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index_CEP(int *y, int *x, char **str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P' || str[i][j] == 'C' || str[i][j] == 'E')
			{
				(*y) = i;
				(*x) = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_way(char **str)
{
	int	y;
	int	x;

	ft_index_CEP(&y, &x, str);
	
	if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
		&& str[i][j - 1] == '1' && str[i][j + 1] == '1' && str[i][j] == 'C')
			return(0);
	else if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
		&& str[i][j - 1] == '1' && str[i][j + 1] == '1' && str[i][j] == 'E')
			return(0);
	else if (str[i - j][x] == '1' && str[i + 1][j] == '1'
		&& str[i][j - 1] == '1' && str[i][j + 1] == '1' && str[i][j] == 'P')
		return(0);
	return(1);
}

/*int	ft_way_ok(char **str)
{
	int y;
	int x;

	y = 0;
	//ft_index_player(&y, &x, var->map);
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y - 1][x] == '1' && str[y + 1] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'C')
			return(0);
			else if (str[y - 1][x] == '1' && str[y + 1] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'E')
			return(0);
			else if (str[y - 1][x] == '1' && str[y + 1] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'P')
		}
	}
	return (1);
}*/


/*int	ft_way_ok(char **str)
{
	int y;
	int x;

	ft_index_player(&y, &x, str);
	if (var->map[y - 1][x] == '1' && var->map[y + 1][x] == '1'&& var->map[y][x - 1] == '1' && var->map[y][x + 1] == '1')
	{
		ft_putstr_fd("Error\nProblem with the way", 2);
		ft_close_map(var);
		return(0);
	}
	return(1);
}
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y - 1][x] == '1' && str[y + 1][x] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'C')
				{
					ft_putstr_fd("Error\nProblem with the way", 2);
					ft_free_tab(str);
					return(0);
				}
			if (str[y - 1][x] == '1' && str[y + 1][x] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'E')
				{
					ft_putstr_fd("Error\nProblem with the way", 2);
					ft_free_tab(str);
					return(0);
				}
			if (str[y - 1][x] == '1' && str[y + 1][x] == '1'
				&& str[y][x - 1] == '1' && str[y][x + 1] == '1' && str[y][x] == 'P')
				{
					ft_putstr_fd("Error\nProblem with the way", 2);
					ft_free_tab(str);
					return(0);
				}
			x++;
		}
		y++;
	}*/
	/*if (ft_way_ok(str) == 0)
	{
		ft_putstr_fd("Error\nProblem with the way", 2);
		ft_free_tab(str);
        return(0);
	}

	return (1);
}*/



/*void	ft_copy(char **str, char *map, t_graph *copy)
{
	int	i;
	int	size;

	ft_copy_init(copy);
	size = ft_line(map) * ft_column(map);
	copy->visit = malloc(sizeof(char *) * (size +1));
	if(!copy->visit)
		return;
	i = 0;
	while(str[i])
	{
		copy->visit[i] = str[i];
		i++;
	}
	//ft_check_all_way(str, copy, i);
}*/


/*int	ft_check_all_way(char **str, t_graph *copy, int i, int j)
{

	ft_index_player(&i, &j, str);
	copy->visit[i][j] = 'A';

	if((str[i + 1][j] != '1') && (!copy->visit[i + 1][j]))
		ft_check_all_way(str, copy, i + 1, j);
	if ((str[i - 1][j] != '1') && (!copy->visit[i - 1][j]))
		ft_check_all_way(str, copy, i - 1, j);
	if ((str[i][j + 1] != '1') && (!copy->visit[i][j + 1]))
		ft_check_all_way(str, copy, i, j + 1);
	if((str[i][j - 1] != '1') && (!copy->visit[i][j - 1]))
		ft_check_all_way(str, copy, i, j - 1);
	if(str[i + 1][j] == 'E' || str[i - 1][j] == 'E' || str[i][j + 1] == 'E' || str[i][j - 1] == 'E')
		return(1);
	else
		return(0);

}*/


	//if((str[i + 1][j] != '1' && str[i + 1][j] != 'E') && (!copy->visit[i + 1][j]))


/*qui sauvergarde ma carte fonction visit[i][j] = str [i][j]
		i++;
		j++;
	

size = 5 - 1 donc 4

soit un tableau qui peut faire ca :

1111
1001
1001
1EC1
1001
1P01
1111

je veux demarrer a P donc je veux dans un premier temps connaitre position
utiliser le ft_index_player et la rappeler a chaque fois qu il a avance de 1.

A chaque fois qu il a avance de 1 je veux verifier les 4 probabilites
s il s agit d un 0 on peut continuer
s il s agit d un 1 il ne peut pas avancer
s il s agit d un C il peut avancer et il faut egalement compter (pour arriver au max)
s il s agit d un E et que C n est pas egal au max il ne peut pas avancer
		si C est egal au max alors le chemin est valide

		Une fois que j ai la position initiale je n ai plus besoin d utiliser ft
		index player. je dois faire avancer manuellement le player pour
		tester les chemins.
*/