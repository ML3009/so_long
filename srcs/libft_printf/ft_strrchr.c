/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:09:20 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 14:30:22 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr( char *s, int c)
{
	int	i;

	i = 0;
	if (!c)
	{
		while (s[i])
		i++;
		return ((char *)&s[i]);
	}
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
	i--;
	}
	return (NULL);
}
