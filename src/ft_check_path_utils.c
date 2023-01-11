/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:53:02 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/11 14:58:04 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	ft_all_collectible(char **str)
{
	int	i;
	int	j;
	int	max_collec;

	max_collec = 0;
	i = 0;
	while(str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if(str[i][j] == 'C')
				max_collec++;
			j++;
		}
		i++;
	}
	return (max_collec);
}
