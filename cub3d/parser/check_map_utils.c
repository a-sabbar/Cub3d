/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:21:38 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 14:02:37 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_new_line(char *value)
{
	int		i;

	i = -1;
	while (value[++i])
	{
		if (value[i] == '\n')
		{
			i++;
			while (value[i] == ' ')
				i++;
			if (value[i] == '1')
			{
				while (value[++i])
				{
					if ((value[i] == '\n' && value[i + 1] == '\n')
						|| (value[i] == '\n' && value[i + 1] == '\0'))
						return (printf("Error\nnew line in map\n"), 1);
				}
				break ;
			}
			else
				i--;
		}
	}
	return (0);
}

int	ft_check_character(char **map, int i, int j, int *nb_player)
{
	j = -1;
	while (map[i][++j])
	{
		if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' \
			&& map[i][j] != 'W' && map[i][j] != 'S'
			&& map[i][j] != 'E' && map[i][j] != ' ')
			return (printf("Error\n  %c is not possible\n", map[i][j]), 0);
		if (map[i][j] == 'N' || map[i][j] == 'W'
			|| map[i][j] == 'S' || map[i][j] == 'E')
			(*nb_player)++;
		if ((*nb_player) == 2)
			return (printf("Error\n number of player\n"), 0);
	}
	return (1);
}
