/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:06:13 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/09 10:33:31 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (y >= 0 && y < W_HEIGHT && x < W_WIDTH && x >= 0)
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
