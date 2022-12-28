/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shifting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:54:58 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/27 16:43:55 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

void    ft_init_shifting(t_map *va)
{
    va->i = 0;
    va->j= 0;
    va->x = 0;
    va->y = 0;
}

static  int ft_size_map(char *av)
{
    char *str;
    int i;
    int fd;

    i = 0;
    fd = open (av, O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        free(str);
        i++;
        str = get_next_line(fd);
    }
    free(str);
    close(fd);
    return (i);
}

char    ft_init_map(char *map)
{
    

}