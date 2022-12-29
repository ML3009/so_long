/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:06:40 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 13:06:57 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(char *line, int c)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != (char)c))
	{
		i++;
	}
	if (line[i] == (char)c)
		return ((char *)line + i);
	else
		return (NULL);
}
