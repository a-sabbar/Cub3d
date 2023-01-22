/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:28:46 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/11 18:51:06 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(char *s)
{	
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_strdup(char *src)
{
	char	*ps1;
	int		i;

	i = 0;
	ps1 = (char *)malloc(ft_strlen(src) + 1);
	if (!ps1)
		return (NULL);
	while (src[i])
	{
		ps1[i] = src[i];
		i++;
	}
	ps1[i] = '\0';
	return (ps1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	rest;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	rest = ft_strlen(s) - (size_t)start;
	if (len > rest)
		len = rest;
	substring = (char *)malloc(len + 1);
	if (!(substring))
		return (NULL);
	while (i < len)
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
