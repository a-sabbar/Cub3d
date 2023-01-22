/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:04:38 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 18:20:19 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**ft_to_int(char **map)
{
	int	i;
	int	j;
	int	**n_map;

	i = -1;
	j = -1;
	n_map = ft_malloc(ft_lenmap(map) * sizeof(int *));
	while (map[++i])
	{
		j = -1;
		n_map[i] = ft_malloc(ft_strlen(map[i]) * sizeof(int));
		while (map[i][++j])
			n_map[i][j] = ft_atoi_map(map[i][j]);
	}
	return (n_map);
}

int	long_line(char **str)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = ft_strlen(str[i]);
	while (str[++i])
	{
		if ((int)ft_strlen(str[i]) > max)
			max = ft_strlen(str[i]);
	}
	return (max);
}

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		printf("Error\nmalloc error\n");
		exit(1);
	}
	return (ptr);
}

void	ft_map_wall(t_data *data, int i, int j)
{
	char	**map;
	int		len;

	i = -1;
	len = long_line(data->map);
	map = ft_malloc((ft_lenmap(data->map) + 1) * sizeof(char **));
	while (data->map[++i])
	{
		j = -1;
		map[i] = ft_malloc(len + 1);
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' ')
				map[i][j] = '1';
			else
				map[i][j] = data->map[i][j];
		}
		j--;
		while (++j < len)
			map[i][j] = '1';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	ft_fre(data->map);
	data->map = map;
}
