/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:51:48 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 09:57:29 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_movement(int x, int y, t_data *data)
{
	if (!data->is_clicked)
	{
		data->mouse.x = x;
		data->mouse.y = y;
	}
	else if ((x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		if (x > data->mouse.x)
		{
			data->player.rotationangle -= (data->player.rotationspeed * \
				(x - data->mouse.x) * M_PI / 180);
		}
		else if (x < data->mouse.x)
			data->player.rotationangle += (data->player.rotationspeed * \
				(data->mouse.x - x) * M_PI / 180);
		data->mouse.x = x;
		data->mouse.y = y;
	}
	return (0);
}

int	button_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->is_clicked = true;
	return (0);
}

int	button_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->is_clicked = false;
	return (0);
}
