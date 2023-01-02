/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:54:23 by ml                #+#    #+#             */
/*   Updated: 2023/01/02 15:44:25 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"


char    **ft_read_map(char *str)
{
    char    **map;
    char    *ret;
    int i;
    int fd;
    int size;

    size = ft_column(str);
    i = 0;
    fd = open(str, O_RDONLY);
    map = malloc(sizeof(char *) * (size + 1));
    if(!map)
        return (NULL);
    ret = get_next_line(fd);
    while (ret)
    {
        map[i] = ret;
        ret = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    free (ret);
    close(fd);
    return(map);

}


void    ft_put_map(t_vars var)
{
    int i;
    int j;

    i = 0;
    while(var.map[i])
    {
        j = 0;
        while(var.map[i][j])
        {
            if(var.map[i][j] == 'P')
                 ft_put_player(var, j, i);
            else if (var.map[i][j] == 'C')
                 ft_put_collectible(var, j, i);
            else if (var.map[i][j] == '0')
                 ft_put_background(var, j, i);
            else if (var.map[i][j] == '1')
                 ft_put_wall(var, j, i);
            else if (var.map[i][j] == 'E')
                   ft_put_exit(var, j, i);
            j++;
        }
        i++;
    }
}
