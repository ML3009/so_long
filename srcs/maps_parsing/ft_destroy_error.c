/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:37:51 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/27 09:39:28 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_destroy_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    while (i >= 0)
    {
        free(map[i])
        i--;
    }
    free(map);
}