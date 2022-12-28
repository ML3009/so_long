/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/27 08:44:24 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

int main(int ac, char **av)
{
	int		fd;
	char	*line;

    if (ac != 2)
        return (ft_printf("Argh... too many arguments"))
    if (ft_check_name(av[1]) != 1)
        return(ft_printf("Format is not OK"))
    fd = open (av[1], O_RDONLY);
    line = get_next_line(fd);
    while ((line = get_next_line(fd)))
    {
        ft_check_parsing()
        //ft_check_map
    }
    /*if (ac != 2)
        return (ft_printf("cest nul"));
    if (ft_check_name(av[1]) != 1)
        return(ft_printf("bof"));
	/*creer variable double pointeur qui check la map. dans cette variable il y aura gnl
    et donc il n existera plus en bas
    fd = open(av[1], O_RDONLY);
    //fd = 1;
	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); 
    }*/
    return (0);
} 
