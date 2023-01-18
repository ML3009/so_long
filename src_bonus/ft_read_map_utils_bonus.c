/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:45:51 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/18 14:29:33 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_column(char *str)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	free (line);
	close (fd);
	len = len - 1;
	return (len);
}

int	ft_line(char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free (line);
		i++;
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (i);
}
