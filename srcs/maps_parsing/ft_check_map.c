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
        return (ft_printf("%s\n","error with the map"));
    while (fd[i])
        i++;
    i--;
    if (fd[i] != 'r' || fd[i - 1] != 'e' || fd[i - 2] != 'b' || fd[i - 3] != '.' || ft_strlen(fd) < 5)
    	return (ft_printf("%s\n","error with the map name"));
    return (1);
}


int ft_check_cep(char **str)
{
    int i;
    int j;
    t_map map;

    map_init(&map);
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == 'P')
                map.player++;
            if (str[i][j] == 'E')
                map.exit++;
            if (str[i][j] == 'C')
                map.collectible++;
            j++;
        }
        i++;
    }
    if (map.player == 1 && map.exit == 1 && map.collectible >= 1)
        return (1);
    else
        return (ft_printf("miss you"));
}