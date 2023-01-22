/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:50 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/16 15:23:27 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ckeck_wall_up_down(t_data *data, double calc_x, double calc_y)
{
	data->player.x += calc_x;
	data->player.y += calc_y;
	if (data->map_int[(int)(data->player.y / TILE)] \
		[(int)(data->player.x / TILE)] == 1)
	{
		data->player.x -= calc_x;
		data->player.y -= calc_y;
	}
}

void	ft_ckeck_wall_left_right(t_data *data)
{
	data->player.x -= (data->player.left_rightdirection \
		* (data->player.movespeed)) * sin(data->player.rotationangle);
	data->player.y += (data->player.left_rightdirection \
		* (data->player.movespeed)) * cos(data->player.rotationangle);
	if (data->map_int[(int)(data->player.y / TILE)] \
		[(int)(data->player.x / TILE)] == 1)
	{
		data->player.x += (data->player.left_rightdirection \
			* data->player.movespeed) * sin(data->player.rotationangle);
		data->player.y -= (data->player.left_rightdirection \
			* data->player.movespeed) * cos(data->player.rotationangle);
	}
}

// int	ft_check_is_wall(t_data *data)
// {
	// double i = 0;
	// double x = data->player.x;
	// double y = data->player.y;
	// while(i < data->player.movespeed)
	// {
	// 	x = data->player.x;
	// 	y = data->player.y;
	// 	x += (data->player.waldirection * (i)) * \
	// 	cos(data->player.rotationangle);
	// 	y += (data->player.waldirection * (i)) * \
	// 	sin(data->player.rotationangle);
	// 	printf("")
	// 	if (data->map_int[(int)floor(y / TILE)][(int)(x / TILE)] == 1)
	// 		return (0);
	// 	i += 0.05;
	// }
	// i = 0;
	// while(i < data->player.movespeed)
	// {
	// 	x = data->player.x;
	// 	y = data->player.y;
	// 	x -= (data->player.waldirection * (i)) * \
	// 	sin(data->player.rotationangle);
	// 	y += (data->player.waldirection * (i)) * \
	// 	sin(data->player.rotationangle);
	// 	if (data->map_int[(int)floor(y / TILE)][(int)(x / TILE)] == 1)
	// 		return (0);
	// 	i += 0.05;
	// }
	// return (1);


int		its_a_wall(t_data *data, int x, int y)
{
	int till;
	int mapx;
	int mapy;
 
	till = TILE;
	mapx = x / till;
	mapy = y / till;
	// printf("map_int[%d][%d] = %d\n", mapy, mapx, data->map_int[mapx][mapy]);
	return (data->map_int[mapy][mapx]);
}

int		wall_check(t_data *data, double newx, double newy)
{
	int x;
	int y;
	int dist;
	int ret;

	x = newx;
	y = newy;
	dist = TILE / 8;
	ret = 0;
	if (its_a_wall(data, x - dist, y - dist) == 1)
		ret = 1;
	if (its_a_wall(data, x + dist, y - dist) == 1)
		ret = 1;
	if (its_a_wall(data, x - dist, y + dist) == 1)
		ret = 1;
	if (its_a_wall(data, x + dist, y + dist) == 1)
		ret = 1;
	return (ret);
}

void	ft_ckeck_between_walls2(t_data *data)
{
	double	x;
	double	y;

	x = (data->player.left_rightdirection \
		* (data->player.movespeed)) * sin(data->player.rotationangle);
	y = (data->player.left_rightdirection \
		* (data->player.movespeed)) * cos(data->player.rotationangle);
	if (data->map_int[(int)(data->player.y / TILE)] \
		[(int)(data->player.x / TILE)] == 3
	&& data->map_int[(int)((data->player.y - y) / TILE)] \
		[(int)((data->player.x + x) / TILE)] == 2)
	{
		data->player.x += x;
		data->player.y -= y;
	}
	if (data->map_int[(int)(data->player.y / TILE)] \
		[(int)(data->player.x / TILE)] == 2
	&& data->map_int[(int)((data->player.y - y) / TILE)] \
		[(int)((data->player.x + x) / TILE)] == 3)
	{
		data->player.x += x;
		data->player.y -= y;
	}
}

void	ft_raycasting_calc(t_data *data)
{
	double move_s;
	// double move_s1 = 0;
	double new_x;
	double new_y;

	new_x = data->player.x;
	new_y = data->player.y;
	data->player.rotationangle = fmod(data->player.rotationangle, 2 * M_PI);
	if (data->player.rotationangle < 0)
		data->player.rotationangle += 2 * M_PI;
	data->player.rotationangle += data->player.turndirection * data->player.rotationspeed;
	move_s = data->player.waldirection * data->player.movespeed;
	new_x = data->player.x + cos(data->player.rotationangle) * move_s;
	new_y = data->player.y + sin(data->player.rotationangle) * move_s;
	new_x = new_x + cos(data->player.rotationangle - (90 * M_PI / 180)) * data->player.left_rightdirection * data->player.movespeed;
	new_y = new_y + sin(data->player.rotationangle - (90 * M_PI / 180)) * data->player.left_rightdirection * data->player.movespeed;
	
	if (wall_check(data, new_x , data->player.y) != 1)
		data->player.x = new_x;
	if (wall_check(data, data->player.x , new_y) != 1)
		data->player.y = new_y;
}
