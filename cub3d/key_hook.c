/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:54:02 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/16 15:24:42 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free_all(data);
		ft_fre2(data->textures.img_data);
		exit(0);
	}
	if (keycode == 124)
		data->player.turndirection = 1;
	if (keycode == 123)
		data->player.turndirection = -1;
	if (keycode == 2)
		data->player.left_rightdirection = -1;
	if (keycode == 0)
		data->player.left_rightdirection = 1;
	if (keycode == 13)
		data->player.waldirection = 1;
	if (keycode == 1)
		data->player.waldirection = -1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 124)
		data->player.turndirection = 0;
	if (keycode == 123)
		data->player.turndirection = 0;
	if (keycode == 2)
		data->player.left_rightdirection = 0;
	if (keycode == 0)
		data->player.left_rightdirection = 0;
	if (keycode == 13)
		data->player.waldirection = 0;
	if (keycode == 1)
		data->player.waldirection = 0;
	return (0);
}

int	cross_x(t_data *data)
{
	int	i;

	i = -1;
	free_all(data);
	ft_fre2(data->textures.img_data);
	while (data->map_int[++i])
		free(data->map_int[i]);
	free(data->map_int);
	exit(0);
}
