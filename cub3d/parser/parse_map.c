/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:24:15 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/16 21:23:15 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_value_utils(char *tmp,
	t_textures **tx, t_color *colors, t_fr_elem *var)
{
	if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2)
		|| !ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2))
	{
		if (!ft_check_value_player(tmp, *tx, var))
			return (0);
	}
	else if (!ft_strncmp(tmp, "F ", 2) && !var->f)
	{
		if (!ft_floor(tmp, colors))
			return (0);
		var->f = 1;
	}
	else if (!ft_strncmp(tmp, "C ", 2) && !var->c)
	{
		if (!ft_ceilling(tmp, colors))
			return (0);
		var->c = 1;
	}
	else
	{
		printf("Error\n textures or colors not correct\n");
		exit(0);
	}
	return (1);
}

int	ft_check_value(t_data *data, char *value, t_textures *tx, t_color *colors)
{
	char		**str;
	char		*tmp;
	int			i;
	int			count;

	i = 0;
	count = -1;
	ft_value(&data->var);
	str = ft_split(value, '\n');
	while (++count < 6)
	{
		tmp = ft_strtrim(str[i], " ");
		while (!tmp[0])
		{
			free(tmp);
			i++;
			tmp = ft_strtrim(str[i], " ");
		}
		if (!ft_check_value_utils(tmp, &tx, colors, &data->var))
			return (free(tmp), ft_fre(str), 1);
		free(tmp);
		i++;
	}
	return (ft_fre(str), 0);
}

int	ft_is_player(int x)
{
	if (x == N || x == S || x == W || x == E)
		return (1);
	return (0);
}
