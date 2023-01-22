/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:02:09 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 19:08:50 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**creat_new_map(char **map, int index)
{
	int		j;
	int		i;
	char	**new;

	i = ft_lenmap(&map[index]);
	new = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (map[index])
	{
		new[j] = ft_strdup(map[index]);
		j++;
		index++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_map(char *value)
{
	char	**map;
	char	**ret;
	char	*tmp;
	int		i;
	int		count;

	map = ft_split(value, '\n');
	i = 0;
	count = 0;
	while (map[i])
	{
		tmp = ft_strtrim(map[i], " ");
		if (tmp[0])
			count++;
		free(tmp);
		if (count == 7)
			break ;
		i++;
	}
	ret = creat_new_map(map, i);
	return (ft_fre(map), ret);
}

int	ft_lenmap(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_fre(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

void	ft_fre2(int **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}
