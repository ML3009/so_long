/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:54:23 by ml                #+#    #+#             */
/*   Updated: 2023/01/23 18:07:40 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_ber(char *fd)
{
	int	i;

	i = 0;
	if (!fd)
	{
		ft_putstr_fd("Error\nFile not found\n", 2);
		exit (1);
	}
	while (fd[i])
		i++;
	i--;
	if (fd[i] != 'r' || fd[i - 1] != 'e' || fd[i - 2] != 'b'
		|| fd[i - 3] != '.' || ft_strlen(fd) < 4)
	{
		ft_putstr_fd("Error\nWrong format. We are waiting for ber\n", 2);
		exit (1);
	}
	return (1);
}

char	**ft_read_map(char *str)
{
	char	**map;
	char	*ret;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nUnknow map name\n", 2);
		exit(1);
	}
	map = malloc(sizeof(char *) * (ft_line(str) + 1));
	if (!map)
		return (NULL);
	ret = get_next_line(fd);
	while (ret)
	{
		map[i++] = ret;
		ret = get_next_line(fd);
	}
	map[i] = NULL;
	free (ret);
	close(fd);
	return (map);
}
