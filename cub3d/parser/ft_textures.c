/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:56:31 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/16 21:27:09 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_read_map(char *file)
{
	char	*str;
	char	*tmp;
	int		fd;

	str = ft_strchr(&file[1], '.');
	if (!str || ft_strcmp(str, ".cub"))
		return (printf("Error\nname of file\n"), NULL);
	fd = open(file, O_RDONLY, 0666);
	if (fd == -1)
		return (printf("Error\n no file with this name\n"), NULL);
	str = NULL;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	if (!str)
		printf("Error\nmap without value !!\n");
	return (str);
}

int	ft_check_is_xpm(char *str)
{
	char	*str1;

	str1 = ft_strrchr(str, '.');
	if (!ft_strcmp(str1, ".xpm"))
		return (1);
	printf("Error\ntexture not xpm\n");
	exit(1);
}

int	ft_check_textures(char *str, t_textures	*tx, int n)
{
	int	i;

	i = 2;
	if (str[i] != ' ')
		return (printf("Error\nno space after texture\n"), 0);
	while (str[i] == ' ')
		i++;
	if (!ft_check_is_xpm(&str[i]))
		return (0);
	if (open(&str[i], O_RDONLY) == -1)
	{
		printf("Error\n textures doesnt exist!!\n");
		exit(1);
	}
	if (n == 1)
		tx->no = ft_strdup(&str[i]);
	else if (n == 2)
		tx->so = ft_strdup(&str[i]);
	else if (n == 3)
		tx->we = ft_strdup(&str[i]);
	else if (n == 4)
		tx->ea = ft_strdup(&str[i]);
	return (1);
}

void	ft_value(t_fr_elem *var)
{
	var->c = 0;
	var->f = 0;
	var->no = 0;
	var->so = 0;
	var->we = 0;
	var->ea = 0;
}

int	ft_check_value_player(char *tmp, t_textures *tx, t_fr_elem *var)
{
	if (!ft_strncmp(tmp, "NO", 2) && !var->no)
	{
		if (!ft_check_textures(tmp, tx, 1))
			return (0);
		var->no = 1;
	}
	else if (!ft_strncmp(tmp, "SO", 2) && !var->so)
	{
		if (!ft_check_textures(tmp, tx, 2))
			return (0);
		var->so = 1;
	}
	else if (!ft_strncmp(tmp, "WE", 2) && !var->we)
	{
		if (!ft_check_textures(tmp, tx, 3))
			return (0);
		var->we = 1;
	}
	else if (!ft_strncmp(tmp, "EA", 2) && !var->ea)
	{
		if (!ft_check_textures(tmp, tx, 4))
			return (0);
		var->ea = 1;
	}
	return (1);
}
