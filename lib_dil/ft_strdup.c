/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:50:15 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup( char *s)
{
	int		i;
	int		size;
	char	*tab;

	size = ft_strlen (s) + 1;
	tab = malloc (size * sizeof(char));
	if (!tab || !s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = s[i];
	i++;
	}
	tab [i] = '\0';
	return (tab);
}
