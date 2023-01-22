/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:51:49 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/11 14:03:44 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_skip_space(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

char	*ft_check_is_color_utils(char *str, int *i, int count)
{
	int		j;
	char	*c;

	j = 0;
	while (ft_isdigit(str[*i]))
	{
		j++;
		(*i)++;
	}
	c = ft_substr(str, *i - j, j);
	*i = ft_skip_space(str, *i);
	if (str[*i] == ',' && count < 2)
		(*i)++;
	else if (str[*i] != '\0')
	{
		printf("Error\n it was not found ','\n");
		free(c);
		exit(0);
	}
	*i = ft_skip_space(str, *i);
	return (c);
}

int	ft_check_is_color(char *str, t_color *color, int n)
{
	int		i;
	int		count;
	char	*c1;

	i = 0;
	count = -1;
	while (++count < 3)
	{
		if (!str[i])
			return (printf("Error\n color !!\n"), 0);
		c1 = ft_check_is_color_utils(str, &i, count);
		if (!ft_isdigit(str[i]) && str[i])
			return (free(c1), printf("Error\n color !!\n"), 0);
		if (n == 1)
			color->c[count] = ft_atoi_color(c1);
		else if (n == 2)
			color->f[count] = ft_atoi_color(c1);
		free(c1);
	}
	i = ft_skip_space(str, i);
	if (str[i])
		return (printf("Error\ncolors should be just three!!?\n"), 0);
	return (1);
}

int	ft_floor(char *str, t_color *color)
{
	int	i;

	i = 1;
	i = ft_skip_space(str, i);
	if (!ft_isdigit(str[i]))
		return (printf("Error\n not digit\n"), 0);
	if (!ft_check_is_color(&str[i], color, 2))
		return (0);
	return (1);
}

int	ft_ceilling(char *str, t_color *color)
{
	int	i;

	i = 0;
	i = ft_skip_space(str, i);
	if (str[i] && str[i] != 'C')
		return (0);
	i += 1;
	i = ft_skip_space(str, i);
	if (!ft_isdigit(str[i]))
		return (printf("Error\n not digit\n"), 0);
	if (!ft_check_is_color(&str[i], color, 1))
		return (0);
	return (1);
}
