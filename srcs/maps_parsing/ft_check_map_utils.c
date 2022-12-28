/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:54:58 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/28 11:40:13 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"


int ft_check_ber(char *fd)
{
    int i;

    i = 0;
    if (!fd)
    {
        ft_putstr_fd("ERROR\nWrong format\n", 2);
        return (0);
    }
    while (fd[i])
        i++;
    i--;
    if (fd[i] != 'r' || fd[i - 1] != 'e' || fd[i - 2] != 'b' || fd[i - 3] != '.' || ft_strlen(fd) < 4)
    {
        ft_putstr_fd("ERROR\nWrong format\n", 2);
        return(0);
    }
    return (1);
}

void    ft_map_init(t_map *map)
{
    map->player = 0;
    map->collectible = 0;
    map->exit = 0;
}

int ft_lenght(char **str)
{
    int fd;
    char *line;
    int len;

    fd = open(*str, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return(0);
    len = ft_strlen(line);
    free(line);
    close(fd);
    len = len - 1;
    return (len);
}

int ft_width (char **str)
{

    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(*str, O_RDONLY);
    line = get_next_line(fd);
    if(!line)
        return(0);
    while (line)
    {
        free(line);
        i++;
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return(i);
}

