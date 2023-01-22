/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:11:40 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 15:18:14 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_front_of_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_y)
	{
		j = -1;
		while (++j < data->map_x)
		{
			if (data->map_int[i][j] == N)
				data->face = 3 * M_PI / 2;
			if (data->map_int[i][j] == S)
				data->face = M_PI / 2;
			if (data->map_int[i][j] == E)
				data->face = 0;
			if (data->map_int[i][j] == W)
				data->face = M_PI;
		}
	}
}
