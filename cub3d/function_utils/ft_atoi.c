/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:39:31 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/11 19:47:29 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

int	ft_atoi_color( char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (result * sign > 255 || result * sign < 0)
	{
		printf("Error\ncolor more 255 or less 0\n");
		exit(1);
	}
	return (result * sign);
}

int	ft_atoi_map(char str)
{
	if (str == '0')
		return (0);
	else if (str == '1')
		return (1);
	else if (str == 'N')
		return (N);
	else if (str == 'W')
		return (W);
	else if (str == 'S')
		return (S);
	else if (str == 'W')
		return (W);
	return (-1);
}

char	**ft_new_map(char **oldmap)
{
	char	**newmap;
	int		i;

	newmap = ft_malloc((ft_lenmap(oldmap) + 1) * sizeof(char *));
	i = -1;
	while (oldmap[++i])
	{
		newmap[i] = ft_strtrim1(oldmap[i], " ");
	}
	newmap[i] = NULL;
	return (newmap);
}

char	*ft_strrchr(char *s, int c)
{
	char	*holder_char;
	size_t	len;

	holder_char = (char *)s;
	len = ft_strlen(holder_char);
	while (len && *holder_char && holder_char[len] != (char) c)
		len--;
	if (holder_char[len] == (char)c)
		return (&holder_char[len]);
	return (NULL);
}
