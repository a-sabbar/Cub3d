/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:14:04 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/16 19:57:54 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_color(t_data *data, double wall, double offset_x, int from_top)
{
	int	offset_y;
	int	pixel_color;

	if (!data->rays[data->id].is_it_vertical
		&& (data->alpha >= 0 && data->alpha < M_PI))
	{
		offset_y = (from_top) * (double)(data->textures.height[0] / wall);
		pixel_color = data->textures.img_data[0][data->textures.width[0] * \
			offset_y + (int)(offset_x * data->textures.width[0])];
		return (pixel_color);
	}	
	else if (!data->rays[data->id].is_it_vertical
		&& !(data->alpha >= 0 && data->alpha < M_PI))
	{
		offset_y = (from_top) * (double)(data->textures.height[1] / wall);
		pixel_color = data->textures.img_data[1][data->textures.width[1] * \
		offset_y + (int)(offset_x * data->textures.width[1])];
		return (pixel_color);
	}
	return (-1);
}

int	find_color_2(t_data *data, double wall, double offset_x, int from_top)
{
	int	offset_y;
	int	pixel_color;

	if (data->rays[data->id].is_it_vertical
		&& (data->alpha >= M_PI / 2 && data->alpha < 1.5 * M_PI))
	{
		offset_y = (from_top) * (double)(data->textures.height[2] / wall);
		pixel_color = data->textures.img_data[2][data->textures.width[2] \
			* offset_y + (int)(offset_x * data->textures.width[2])];
		return (pixel_color);
	}
	else if (data->rays[data->id].is_it_vertical
		&& !(data->alpha >= M_PI / 2 && data->alpha < 1.5 * M_PI))
	{
		offset_y = (from_top) * (double)(data->textures.height[3] / wall);
		pixel_color = data->textures.img_data[3][data->textures.width[3] * \
			offset_y + (int)(offset_x * data->textures.width[3])];
		return (pixel_color);
	}
	return (-1);
}

void	ft_draw_wall(t_data *data, int start, int len, double wall)
{	
	int			pixel_color;
	double		offset_x;
	int			from_top;

	if (data->rays[data->id].is_it_vertical)
		offset_x = (data->rays[data->id].y / TILE);
	else
		offset_x = (data->rays[data->id].x / TILE);
	offset_x = offset_x - floor(offset_x);
	if (len > W_HEIGHT)
		len = W_HEIGHT;
	while (start < len)
	{
		from_top = start + wall / 2 - W_HEIGHT / 2;
		data->alpha = fmod(data->alpha, 2 * M_PI);
		pixel_color = find_color(data, wall, offset_x, from_top);
		if (pixel_color < 0)
			pixel_color = find_color_2(data, wall, offset_x, from_top);
		my_mlx_pixel_put(&data->img, data->id, start, pixel_color);
		start++;
	}
}
