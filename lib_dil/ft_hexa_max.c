/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:00:33 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_hexa_max(unsigned int nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		len += ft_hexa_max (nb / 16);
		len += ft_putchar (base[nb % 16]);
	}
	else
		len += ft_putchar (base[nb]);
	return (len);
}
