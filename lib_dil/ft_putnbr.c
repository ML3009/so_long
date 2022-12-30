/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:12:36 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/30 10:44:27 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	long long int	i;
	int				len;

	len = 0;
	i = n;
	if (i == -2147483648)
		len += ft_putstr ("-2147483648");
	else if (i < 0)
	{
		len += ft_putchar ('-');
		len += ft_putnbr (-i);
	}
	else if (i > 9)
	{
		len += ft_putnbr (i / 10);
		len += ft_putchar (i % 10 + '0');
	}
	else
	len += ft_putchar (i + '0');
	return (len);
}
