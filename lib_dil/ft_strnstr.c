/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:55:50 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr( char *big,  char *little, size_t len)
{
	size_t	i;
	size_t	lenbis;

	i = 0;
	lenbis = ft_strlen((char *)little);
	if (!big && len == 0)
		return (NULL);
	if (lenbis == 0)
		return ((char *)big);
	while (big[i] && len)
	{
		if (ft_strncmp((char *)&big[i], (char *)little, lenbis) == 0
			&& lenbis <= len)
		{
			if ((i + lenbis) > len)
				return (NULL);
			return ((char *)&big[i]);
		}
	i++;
	}
	return (NULL);
}
