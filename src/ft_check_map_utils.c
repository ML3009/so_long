/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:31:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/06 16:56:29 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int ft_check_ber(char *fd)
{
    int i;

    i = 0;
    if (!fd)
    {
        ft_putstr_fd("Error\nWrong format\n", 2);
        exit (1);
    }
    while (fd[i])
        i++;
    i--;
    if (fd[i] != 'r' || fd[i - 1] != 'e' || fd[i - 2] != 'b' || fd[i - 3] != '.' || ft_strlen(fd) < 4)
    {
        ft_putstr_fd("Error\nWrong format\n", 2);
        exit (1);
    }
    return (1);
}

void    ft_map_init(t_utils *map)
{

    map->player = 0;
    map->collectible = 0;
    map->exit = 0;
}

int ft_line(char *str)
{
    int fd;
    char *line;
    int len;

    fd = open(str, O_RDONLY);
    line = get_next_line(fd);
    if (!line)
        return(0);
    len = ft_strlen(line);
    free(line);
    close(fd);
    len = len - 1;
    return (len);
}

int ft_column (char *str)
{

    int fd;
    char *line;
    int i;

    i = 0;
    fd = open(str, O_RDONLY);
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

int ft_check_map (char **str, char *map)
{
	if (ft_check_size(str) == 0)
	{
		ft_putstr_fd("Error\nWrong map size\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	if (ft_check_wall(str, map) == 0)
	{
		ft_putstr_fd("Error\nWrong wall placement\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	if (ft_check_parsing(str) == 0)
	{
		ft_putstr_fd("Error\nUnknow character\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	if (ft_check_occurence(str) == 0)
	{
		ft_putstr_fd("Error\nProblem with CEP\n", 2);
		ft_free_tab(str);
		exit(1);
	}
	/*if (ft_check_way(str) == 0)
	{
		ft_putstr_fd("Error\nProblem with the way", 2);
		ft_free_tab(str);
        exit(1);
	}*/
	return(1);
}
