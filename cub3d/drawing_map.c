/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:07:48 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 10:00:08 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_cub(int i, int j, t_image img, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			my_mlx_pixel_put(&img, \
				(j * 10) + x, (i * 10) + y, color);
	}
}

void	ft_draw_player_x(int i, t_image img, int color)
{
	int	x;
	int	y;

	i = -1;
	while (++i < 21)
	{
		y = -1;
		while (++y < 10)
		{
			x = -1;
			while (++x < 10)
			{
				my_mlx_pixel_put(&img, \
					(0 * 10) + x, ((i - 1) * 10) + y, color);
				my_mlx_pixel_put(&img, \
					(21 * 10) + x, ((i - 1) * 10) + y, color);
				my_mlx_pixel_put(&img, \
					((i + 1) * 10) + x, (0 * 10) + y, color);
				my_mlx_pixel_put(&img, \
					((i + 1) * 10) + x, (20 * 10) + y, color);
				my_mlx_pixel_put(&img, \
					x, (20 * 10) + y, color);
			}
		}
	}
}

void	ft_draw_background(int i, int j, t_image img)
{
	int	x;
	int	y;

	i = -1;
	while (++i < 21)
	{
		j = -1;
		while (++j < 21)
		{
			y = -1;
			while (++y < 10)
			{
				x = -1;
				while (++x < 10)
					my_mlx_pixel_put(&img, \
						(j * 10) + x, (i * 10) + y, 0xD6D58E);
			}
		}
	}
}

void	ft_draw_wall_minimap(t_data data, int i, int j, t_image img)
{
	double	draw_x;
	double	draw_y;

	draw_x = data.player.x / TILE - 10;
	draw_y = data.player.y / TILE - 10;
	i = 21;
	while (--i != 0)
	{
		if ((draw_y + i) < data.map_y && (draw_y + i) > 0)
		{
			j = 21;
			while (--j != 0)
			{
				if (data.map_int[(int)floor(draw_y + i)] \
				[(int)floor(draw_x + j)] == 1
					&& (draw_x + j) < data.map_x && (draw_x + j) > 0)
					ft_draw_cub(i, j, img, 0x042940);
			}
		}
	}
}

void	ft_draw_map(t_data data, int i, int j, t_image img)
{
	double	draw_x;
	double	draw_y;

	draw_x = data.player.x / TILE - 10;
	draw_y = data.player.y / TILE - 10;
	ft_draw_background(i, j, img);
	ft_draw_wall_minimap(data, i, j, img);
	ft_draw_player_x(i, img, 0x005C53);
}
