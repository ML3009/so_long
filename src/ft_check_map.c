/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:12:33 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 11:42:29 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int ft_check_size (char **str)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen (str[0]);
	while (str[i])
	{
		if (len != ft_strlen(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_check_wall (char **str, char *map)
{
	int i;
	int j;
	int i_max;
	int j_max;

	i_max = ft_column(map) - 1;
	j_max = ft_line(map) - 1;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < ft_strlen(str[i]) - 1)
		{
			if (str[0][j] != '1' || str[i_max][j] != '1')
				return (0);
			else if (str[i][j_max]!= '1' || str[i][0] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_parsing(char **str)
{
	int i;
	int j;
	int size;

	size = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < size - 1)
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'C'
				&& str[i][j] != 'E' && str[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int ft_check_occurence (char **str)
{
	int i;
	int j;
	t_utils map;

	ft_map_init(&map);

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				map.player++;
			}
			if (str[i][j] == 'E')
				map.exit++;
			if (str[i][j] == 'C')
				map.collectible++;
			j++;
		}
		i++;
	}
	if (map.player !=1 || map.exit != 1 || map.collectible == 0)
		return(0);
	return (1);
}

/*int	ft_check_way(char **str)
{
	int i;
	int j;
	int size;

	size = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < size - 1)
		{
			if ((str[i][j] == 'C' || str[i][j] == 'E' || str[i][j] == 'P')
				&& (str[i - 1][j] == '1' && str[i + 1][j] == '1'
					&& str[i][j - 1] == '1' && str[i][j + 1] == '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}*/

/*int	ft_check_way(char **str)
{
	int	i;
	int	j;
	int	size;
	int	c_max;
	int	c;

	c = 0;
	size = ft_strlen(str[0]);
	i = 0;
	j = 0;
	c_max = ft_all_collectible(str);
	ft_index_player(&i, &j, str);
	while (str[i])
	{
		while (j < size - 1)
		{
			if(str[i][j] == 'C')
				c++;
			ft_check_all_way (str, i, j);
			if((str[i + 1][j] == 'E' || str[i - 1][j] == 'E' || str[i][j + 1] == 'E' || str[i][j - 1] == 'E')&&(c == c_max))
				return(1);
			j++;
		}
		i++;
	}
	return(0);
}
*/
void	**ft_copy(char **str, char *map)
{
	int	i;
	int j;
	int	size;
	t_graph copy;

	j = 0;
	ft_copy_init(&copy);
	size = ft_line(map) * ft_column(map);
	copy.visit = malloc(sizeof(char *) * (size +1));
	if(!copy.visit)
		return(0);
	i = 0;
	while(str[i])
	{
		copy.visit[i] = str[i];
		i++;
	}
	ft_check_all_way(str, &copy, i, j);
}


int	ft_check_all_way(char **str, t_graph *copy, int i, int j)
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

}


	//if((str[i + 1][j] != '1' && str[i + 1][j] != 'E') && (!copy->visit[i + 1][j]))


/*qui sauvergarde ma carte fonction visit[i][j] = str [i][j]
		i++;
		j++;
	*/

/*size = 5 - 1 donc 4

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


int	ft_check_way(char **str)
{
	int i;
	int j;

	ft_index_player(&i, &x, str);
	while (str[i])
	{
		while(str[i][j])
		{
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
	}
}


cas ou il y a tous les murs autour du personnage des le debut :
	if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
				&& str[i][j - 1] == '1' && str[i][j + 1] == '1')
			return(0);

	if (str[i - 1][j] == '0' && str[i + 1][j] == '1'
				&& str[i][j - 1] == '1' && str[i][j + 1] == '1')

	if (str[i - 1][j] == '1' && str[i + 1][j] == '0'
				&& str[i][j - 1] == '1' && str[i][j + 1] == '1')

	if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
				&& str[i][j - 1] == '0' && str[i][j + 1] == '1')

	if (str[i - 1][j] == '1' && str[i + 1][j] == '1'
				&& str[i][j - 1] == '1' && str[i][j + 1] == '0')


Nous partons de la position du joueur.

Possibilite d avancer =

	if (str[i - 1][j] == '0' || str[i + 1][j] == '0'
				|| str[i][j - 1] == '0' || str[i][j + 1] == '0')
				return (1);

	if (str[i - 1][j] == 'C' || str[i + 1][j] == 'C'
				|| str[i][j - 1] == 'C' || str[i][j + 1] == 'C')
				return (1);
				C++;

Impossibilite d'avancer et donc il faut reculer =

	if (str[i - 1][j] == '1' || str[i + 1][j] == '1'
				|| str[i][j - 1] == '1' || str[i][j + 1] == '1')
				return (1);




Condition de succes =

	if ((str[i - 1][j] == 'E' || str[i + 1][j] == 'E'
				|| str[i][j - 1] == 'E' || str[i][j + 1] == 'E') && C == C_max)
				return(1) + FINI.


	verifier d abord str[i] et donc tant que str[i + 1] == '0' ou 'C' on avance.
	Si str[i + 1] == '1' ou 'E' && C!= C_max alors on passe au check de i -.
	Si str[i - 1] == '1' ou 'E' && C!= C_max alors on passe au check de j.
	Si str[i][j + 1] == '1' ou 'E' && C!= C_max alors on passe au check de j -.
	Si str[i][j - 1] == '1' ou 'E' && C!= C_max alors on se souvient de ce chemin et retente.






diviser par la size - 1
	while(str[i][j])
	{
	if(str[i + 1][j] == '1' || str[i + 1][j] == 'E' && C!= C_max)


	if(str[i - 1][j] == '1' || str[i - 1][j] == 'E' && C!= C_max)


	if(str[i][j + 1] == '1' || str[i][j + 1] == 'E' && C!= C_max)


	if(str[i][j - 1] == '1' || str[i][j - 1] == 'E' && C!= C_max)



	}
}

on rappel la fonction et on recommence. */


