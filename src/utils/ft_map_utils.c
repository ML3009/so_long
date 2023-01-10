/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/utils/ft_map_utils.c
/*   Created: 2023/01/10 10:45:51 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/10 11:18:33 by mvautrot         ###   ########.fr       */
=======
/*   Created: 2023/01/02 17:31:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/06 16:56:29 by ml               ###   ########.fr       */
>>>>>>> e4f02b920e9187a13584b4e58fba9fce67c8978d:src/ft_check_map_utils.c
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

<<<<<<< HEAD:src/utils/ft_map_utils.c
=======
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

>>>>>>> e4f02b920e9187a13584b4e58fba9fce67c8978d:src/ft_check_map_utils.c
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

void    ft_map_init(t_utils *map)
{

    map->player = 0;
    map->collectible = 0;
    map->exit = 0;
}

void    ft_var_init(t_vars *var)
{

    var->collec_count = 0;
}


int	ft_all_collectible(char **str)
{
	int	i;
	int	j;
	int	max_collec;

	max_collec = 0;
	i = 0;
	while(str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if(str[i][j] == 'C')
				max_collec++;
			j++;
		}
		i++;
	}
	return (max_collec);
}
