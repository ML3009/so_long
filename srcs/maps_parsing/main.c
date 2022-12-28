/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/28 14:18:04 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

int main(int ac, char **av)
{
	int		fd;
    int i;
    int size;
	char	*line;
    char    **str;

    if (ac != 2)
        return (ft_printf(" too many arguments"));
    if (ft_check_ber(av[1]) != 1)
        return(ft_printf("Format is not OK"));
    size = ft_column(av[1]);
    i = 0;
    fd = open (av[1], O_RDONLY);
    str = malloc(sizeof(char *) * (size + 1));
    if (!str)
        return (0);
    line = get_next_line(fd);
    while ((line))
    {
        str[i] = line;
        line = get_next_line(fd);
        i++;
    }
    str[i] = NULL;
    ft_check_map(str, av[1]);
    free(line);
    close(fd);
   // return(map);
        //ft_check_map
    }
    /*if (ac != 2)
        return (ft_printf("cest nul"));
    if (ft_check_name(av[1]) != 1)
        return(ft_printf("bof"));
	creer variable double pointeur qui check la map. dans cette variable il y aura gnl
    et donc il n existera plus en bas
    fd = open(av[1], O_RDONLY);
    //fd = 1;
	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }*/

