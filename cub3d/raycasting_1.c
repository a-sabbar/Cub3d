/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:44:15 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/16 11:40:33 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_horizontal_calc(t_data data, t_vector	*step_h, t_vector	*a_h)
{
	if (data.player.rotationangle >= 0 && data.player.rotationangle <= M_PI)
		a_h->y = floor(data.player.y / TILE) * TILE + TILE;
	else
		a_h->y = floor(data.player.y / TILE) * TILE;
	a_h->x = data.player.x + \
			((a_h->y - data.player.y) / tan(data.player.rotationangle));
	step_h->y = TILE;
	if (!(data.player.rotationangle >= 0 && data.player.rotationangle <= M_PI))
		step_h->y *= -1;
	step_h->x = TILE / tan(data.player.rotationangle);
	if (data.player.rotationangle >= \
	M_PI / 2 && data.player.rotationangle <= M_PI * 1.5)
	{
		if (step_h->x >= 0)
			step_h->x *= -1;
	}
	else if (step_h->x < 0)
		step_h->x *= -1;
}

void	ft_vertical_calc(t_data data, t_vector	*step_v, t_vector	*a_v)
{
	if (data.player.rotationangle >= M_PI / 2
		&& data.player.rotationangle <= M_PI * 1.5)
		a_v->x = floor(data.player.x / TILE) * TILE;
	else
		a_v->x = floor(data.player.x / TILE) * TILE + TILE;
	a_v->y = data.player.y + \
		((a_v->x - data.player.x) * tan(data.player.rotationangle));
	step_v->x = TILE;
	if (data.player.rotationangle >= \
		M_PI / 2 && data.player.rotationangle <= M_PI * 1.5)
		step_v->x *= -1;
	step_v->y = TILE * tan(data.player.rotationangle);
	if (data.player.rotationangle >= 0 && data.player.rotationangle <= M_PI)
	{
		if (step_v->y < 0)
			step_v->y *= -1;
	}
	else if (step_v->y > 0)
		step_v->y *= -1;
}

int	ft_check_vertical(t_data data, t_vector	*step_v, t_vector	*a_v, int *v)
{
	if ((a_v->y >= data.map_y * TILE) || (a_v->x >= data.map_x * TILE))
		return (0);
	if (a_v->y < 0 || (a_v->x < 0))
		return (0);
	if (data.player.rotationangle >= M_PI / 2
		&& data.player.rotationangle <= M_PI * 1.5)
	{
		if (data.map_int[(int)floor(a_v->y / TILE)] \
			[(int)floor((a_v->x - TILE) / TILE)] == 1)
			return ((*v) = 1, 0);
	}
	else
	{
		if (data.map_int[(int)floor(a_v->y / TILE)] \
			[(int)floor(a_v->x / TILE)] == 1)
			return ((*v) = 1, 0);
	}
	return (a_v->x += step_v->x, a_v->y += step_v->y, 1);
}

int	ft_check_horizontal(t_data data, t_vector *step_h, t_vector *a_h, int *h)
{
	if ((a_h->y >= data.map_y * TILE)
		|| (a_h->x >= data.map_x * TILE) || cos(data.player.rotationangle) == 1)
		return (0);
	if (a_h->y < 0 || (a_h->x < 0) || cos(data.player.rotationangle) == 0)
		return (0);
	if (!(data.player.rotationangle >= 0
			&& data.player.rotationangle <= M_PI))
	{
		if (data.map_int[(int)floor((a_h->y - TILE) / TILE)] \
			[(int)floor(a_h->x / TILE)] == 1)
			return ((*h) = 1, 0);
	}
	else
	{
		if (data.map_int[(int)floor(a_h->y / TILE)] \
			[(int)floor(a_h->x / TILE)] == 1)
			return ((*h) = 1, 0);
	}
	return (a_h->y += step_h->y, a_h->x += step_h->x, 1);
}

t_vector	ft_check_calc(t_data data, t_calc calc, t_vector a_h, t_vector a_v)
{
	if (calc.h)
		calc.dis_h = sqrt(pow((data.player.y - a_h.y), 2) \
			+ pow((data.player.x - a_h.x), 2));
	else
		calc.dis_h = -1;
	if (!calc.v)
	{
		a_h.is_it_vertical = false;
		return (a_h);
	}
	else if (!calc.h)
	{
		a_v.is_it_vertical = true;
		return (a_v);
	}
	if (calc.dis_v < calc.dis_h)
	{
		a_v.is_it_vertical = true;
		return (a_v);
	}
	a_h.is_it_vertical = false;
	return (a_h);
}
