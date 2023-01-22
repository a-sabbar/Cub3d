/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:16:13 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/11 18:27:25 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_is_close_condition(char **map, int i, int j)
{
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1'
	&& map[i + 1][j] != 'N' && map[i + 1][j] != 'W'
	&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E')
		return (printf("Error\nmap is not closed \
by 1 in (%d -  %d) \n", i, j), 0);
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1'
	&& map[i - 1][j] != 'N' && map[i - 1][j] != 'W'
	&& map[i - 1][j] != 'S' && map[i - 1][j] != 'E')
		return (printf("Error\nmap is not \
closed by 1in (%d -  %d) \n", i, j), 0);
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1'
	&& map[i][j + 1] != 'N' && map[i][j + 1] != 'W'
	&& map[i][j + 1] != 'S' && map[i][j + 1] != 'E')
		return (printf("Error\nmap is not closed by 1 in \
(%d -  %d) \n", i, j), 0);
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && map[i][j - 1] != 'N'
		&& map[i][j - 1] != 'W' && map[i][j - 1] != 'S' && map[i][j - 1] != 'E')
		return (printf("Error\n map is not closed \
by 1 in (%d -  %d) \n", i, j), 0);
	return (1);
}

int	ft_check_is_close(char **map, int i, int j)
{
	j = -1;
	while (map[i][++j])
	{
		if (map[i][j] == '0')
		{
			if (j > (int)ft_strlen(map[i - 1])
				|| j > (int)ft_strlen(map[i + 1]))
				return (printf("Error\nmap is not closed (%d -  %d) \n",
						i, j), 0);
			if (ft_check_is_close_condition(map, i, j) == 0)
				return (0);
		}
	}
	return (1);
}

int	ft_check_map_utils(char **map, int i, int j)
{
	i = -1;
	while (map[++i])
	{
		if (!ft_check_is_close(map, i, 0))
			return (0);
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W'
			|| map[i][j] == 'S' || map[i][j] == 'E')
			{
				if ((map[i - 1][j] != '0' && map[i - 1][j] != '1' )
				|| (map[i + 1][j] != '0' && map[i + 1][j] != '1' )
				|| (map[i][j - 1] != '0' && map[i][j - 1] != '1' )
				|| (map[i][j + 1] != '0' && map[i][j + 1] != '1' ))
					return (printf("Error :\n position of player\n"), 0);
			}
		}
	}
	return (1);
}

int	ft_check_map(char **map, int i, int j)
{
	int	nb_player;

	i = -1;
	nb_player = 0;
	while (map[++i])
	{
		if (!ft_check_character(map, i, 0, &nb_player))
			return (0);
	}
	if (nb_player == 0)
		return (printf("Error\nNo player\n"), 0);
	i = 0;
	while (map[0][i] == '1' || map[0][i] == ' ')
		i++;
	if (map[0][i] != '\0')
		return (printf("Error\nfirst line should be : 1 \n"), 0);
	j = ft_lenmap(map) - 1;
	i = 0;
	while (map[j][i] == '1' || map[j][i] == ' ')
		i++;
	if (map[j][i] != '\0')
		return (printf("Error\nlast line should be : 1\n"), 0);
	if (!ft_check_map_utils(map, i, j))
		return (0);
	return (1);
}
