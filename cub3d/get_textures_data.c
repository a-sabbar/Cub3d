/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:47:49 by youchenn          #+#    #+#             */
/*   Updated: 2022/10/11 18:07:07 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalide_texture(void *img, t_data *data)
{
	(void)data;
	if (!img)
	{
		write(2, "texture invalide\n", 18);
		free_all(data);
		exit(1);
	}
}

void	get_textures(t_data *data)
{
	int	a;

	data->textures.img_data = (int **)malloc((sizeof(int *) * 4));
	data->textures.img = mlx_xpm_file_to_image(data->mlx, data->textures.ea, \
		&data->textures.width[0], &data->textures.height[0]);
	invalide_texture(data->textures.img, data);
	data->textures.img_data[0] = (int *)mlx_get_data_addr(data->textures.img, \
	&a, &a, &a);
	data->textures.img = mlx_xpm_file_to_image(data->mlx, data->textures.no, \
	&data->textures.width[1], &data->textures.height[1]);
	invalide_texture(data->textures.img, data);
	data->textures.img_data[1] = (int *)mlx_get_data_addr(data->textures.img, \
	&a, &a, &a);
	data->textures.img = mlx_xpm_file_to_image(data->mlx, data->textures.so, \
	&data->textures.width[2], &data->textures.height[2]);
	invalide_texture(data->textures.img, data);
	data->textures.img_data[2] = (int *)mlx_get_data_addr(data->textures.img, \
	&a, &a, &a);
	data->textures.img = mlx_xpm_file_to_image(data->mlx, data->textures.we, \
	&data->textures.width[3], &data->textures.height[3]);
	invalide_texture(data->textures.img, data);
	data->textures.img_data[3] = (int *)mlx_get_data_addr(data->textures.img, \
	&a, &a, &a);
}
