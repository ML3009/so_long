/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 15:10:13 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/libft.h"

int main(int ac, char **av)
{
	int		fd;
	char	*line;

    if (ac != 2)
        return (ft_printf("cest nul"));
    if (ft_check_name(av[1]) != 1)
        return(0);
	fd = open(av[1], O_RDONLY);
    //fd = 1;
	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); 
    }
    return (0);
} 


/*int main(void)
{
	int fd1;
	int fd2;
	char *line;
    char *line2;
	fd1 = open ("salut.txt", O_RDONLY);
	fd2 = open ("txt.txt", O_RDONLY);
	while ((line = get_next_line(fd1)) && (line2 = get_next_line(fd2)))
	{
    	printf("%s", line);
        printf ("%s", line2);
		free(line);
        free(line2);
    }
	return(0);
}*/

/*int    main(int argc, char **argv)
{
    int    fd;
    char    *readed;

    if (argc == 0)
        return (0);
    if (fd < 0 || fd == -1)
        return (0);
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        readed = get_next_line(fd);
        printf("%s\n", readed);
        if (!readed)
            break ;
    }
    return (0);
}*/
