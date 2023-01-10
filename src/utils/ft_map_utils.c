/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:45:51 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/10 14:18:16 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"

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
    var->collectable = 0;
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
