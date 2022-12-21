/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:12:33 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/21 11:42:29 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/get_next_line.h"
# include "../../includes/ft_printf.h"
# include "../../includes/libft.h"

int ft_check_name(char *file)
{
    int i;

    i = 0;
    if (!file)
        return (ft_printf("error with the map"));
    while (file[i])
        i++;
    i--;
    if (file[i] != 'r' || file[i - 1] != 'e' || file[i - 2] != 'b' || file[i - 3] != '.' || ft_strlen(file) < 4)
    	return (ft_printf("error with the map name"));
    return (1);
}
