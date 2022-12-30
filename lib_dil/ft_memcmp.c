/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:10:02 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp( void *s1,  void *s2, size_t n)
{
	size_t				i;
	 unsigned char	*s3;
	 unsigned char	*s4;

	s3 = ( unsigned char *)s1;
	s4 = ( unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((s3[i] != s4[i]))
			return (s3[i] - s4[i]);
	i++;
	}
	return (0);
}
