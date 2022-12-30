/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:42:01 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char  *s1, char  *set)
{
	char	*tab;
	size_t	lens1;
	size_t	i;

	i = 0;
	lens1 = ft_strlen (s1);
	while (s1[i] && ft_strchr (set, s1[i]))
		i++;
	while (s1[lens1 - 1] && ft_strchr(set, s1[lens1 - 1]) && lens1 > i)
		lens1 --;
	tab = (char *) malloc (sizeof(char) * (lens1 - i + 1));
	if (!(tab))
		return (NULL);
	if (tab)
		ft_strlcpy(tab, &s1[i], lens1 - i + 1);
	return (tab);
}
