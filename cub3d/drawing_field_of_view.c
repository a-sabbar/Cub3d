/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_field_of_view.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:29:01 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/16 14:15:14 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_virtualwall_utils(t_data *data, int i, int j)
{
	if (ft_is_player(data->map_int[i][j]) && data->map_int[i + 1][j] \
	== 1 && data->map_int[i - 1][j] == 1 && data->map_int[i][j - 1] \
	== 1 && data->map_int[i][j - 1] == 1)
	{
		data->map_int[i][j] = 2;
		data->map_int[i - 1][j - 1] = 3;
		data->map_int[i + 1][j - 1] = 3;
		data->map_int[i + 1][j + 1] = 3;
		data->map_int[i - 1][j + 1] = 3;
	}
}

void		ft_virtualwall(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_y)
	{
		j = -1;
		while (++j < data->map_x)
		{
			if (data->map_int[i][j] == 0 && data->map_int[i - 1][j] == 1
			&& data->map_int[i][j + 1] == 1 && data->map_int[i - 1][j + 1] == 0)
			{
				data->map_int[i][j] = 2;
				data->map_int[i - 1][j + 1] = 3;
			}
			if (data->map_int[i][j] == 0 && data->map_int[i + 1][j] == 1
			&& data->map_int[i][j + 1] == 1 && data->map_int[i + 1][j + 1] == 0)
			{
				data->map_int[i][j] = 2;
				data->map_int[i + 1][j + 1] = 3;
			}
			ft_virtualwall_utils(data, i, j);
		}
	}
}

void	ft_draw_field_of_view(t_data *data)
{
	double	rotation;
	int		i;

	rotation = data->player.rotationangle;
	data->player.rotationangle -= FOFV / 2;
	i = W_WIDTH + 1;
	while (--i)
	{
		data->player.rotationangle = fmod(data->player.rotationangle, 2 * M_PI);
		if (data->player.rotationangle <= 0)
			data->player.rotationangle += 2 * M_PI;
		data->rays[data->id] = ft_len_of_line(*data);
		data->dis_rays[data->id] = \
			sqrt(pow((data->player.y - data->rays[data->id].y), 2) \
				+ pow((data->player.x - data->rays[data->id].x), 2));
		data->player.rotationangle += FOFV / W_WIDTH;
		data->id++;
		if (data->id == W_WIDTH)
			data->id = 0;
	}
	data->player.rotationangle = rotation;
}

void	ft_draw_player(t_image	img)
{
	my_mlx_pixel_put(&img, 105, 105, 0x000000);
	my_mlx_pixel_put(&img, 105 - 1, 105, 0x000000);
	my_mlx_pixel_put(&img, 105, 105 - 1, 0x000000);
	my_mlx_pixel_put(&img, 105 + 1, 105, 0x000000);
	my_mlx_pixel_put(&img, 105, 105 + 1, 0x000000);
}

int	ft_draw(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	ft_raycasting_calc(data);
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	ft_draw_field_of_view(data);
	ft_rendering_wall(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
	return (0);
}
