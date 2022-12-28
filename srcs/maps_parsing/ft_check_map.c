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

# include "../../includes/libft.h"
# include "../../includes/so_long.h"

int ft_check_name(char *fd)
{
    int i;

    i = 0;
    if (!fd)
        return (ft_putstr_fd("ERROR\nWrong format\n", 2));
    while (fd[i])
        i++;
    i--;
    if (fd[i] != 'r' || fd[i - 1] != 'e' || fd[i - 2] != 'b' || fd[i - 3] != '.' || ft_strlen(fd) < 5)
    	return (ft_putstr_fd("ERROR\nWrong format\n", 2));
    return (1);
}


int ft_check_parsing(char *map_str)
{
    int i;
    
    i = 0;
    while (map_str[i])
    {
       if (map_str[i] != '1' && map_str[i] != '0' && map_str[i] != 'C'
            && map_str[i] != 'E' && map_str[i] != 'P')
        {
            free (map_str);
            ft_putstr_fd("ERROR\nCaractere is not OK\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

void    ft_count_occurence(int *count_c, int *count_e, int *count_p, char c)
{
    if (c == 'C')
        *count_c++;
    if (c == 'E')
        *count_e++;
    if (c == 'P')
        *count_p++;
}

int ft_check_occurence(char **map)
{
    t_map va; 
    int count_c;

    count_c = 0;
    ft_map_init(&va);
    while (map[va.i])
    {
        while (map[va.i][va.j])
        {
            ft_count_occurence(&count_c, &va.x, &va.y, map[va.i][va.j]);
            va.j++;
        }
        va.j = 0;
        va.i ++;
    }
    if (va.x != 1 || va.y != 1 || c == 0)
    {
        ft_destroy_map(map);
        ft_putstr_fd("ERROR\nProblem with CEP\n", 2);
        return(0);
    }
    return (1);
}