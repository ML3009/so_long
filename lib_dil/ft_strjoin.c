/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:04:05 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *line, char *buf)
{
	char	*tab;
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = (ft_strlen(line) + ft_strlen(buf));
	tab = malloc (sizeof(char) * (size + 1));
	new = tab;
	if (!new)
		return (NULL);
	while (line && line[i])
	{
		tab[i] = line[i];
		i++;
	}
	while (*buf)
	{
		tab[i++] = *buf++;
	}
	tab[size] = '\0';
	free (line);
	return (new);
}