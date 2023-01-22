/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:38:01 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/11 16:06:53 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	ft_position_player(t_data data)
{
	int			i;
	int			j;
	t_vector	posi;

	i = -1;
	while (data.map[++i])
	{
		j = -1;
		while (data.map[i][++j])
		{
			if (data.map[i][j] != '1' && data.map[i][j] != '0'
			&& data.map[i][j] != ' ')
			{
				posi.y = i;
				posi.x = j;
				return (posi);
			}
		}
	}
	exit(0);
}

void	ft_window(t_data data)
{
	t_vector	posi_player;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "CUB3D");
	get_textures(&data);
	data.player.turndirection = 0;
	data.player.waldirection = 0;
	data.player.rotationangle = data.face;
	data.player.movespeed = 1.5;
	data.player.rotationspeed = 3 * (M_PI / 180);
	posi_player = ft_position_player(data);
	data.player.y = posi_player.y * TILE;
	data.player.x = posi_player.x * TILE;
	data.posi_player = posi_player;
	data.is_clicked = false;
	data.mouse.x = 0;
	mlx_loop_hook(data.mlx, ft_draw, &data);
	mlx_hook(data.mlx_win, 2, 0L, key_hook, &data);
	mlx_hook(data.mlx_win, 4, 0L, button_press, &data);
	mlx_hook(data.mlx_win, 5, 0L, button_release, &data);
	mlx_hook(data.mlx_win, 6, 0, mouse_movement, &data);
	mlx_hook(data.mlx_win, 17, 0L, cross_x, &data);
	mlx_hook(data.mlx_win, 3, 0L, key_release, &data);
	mlx_loop(data.mlx);
}

void	free_all(t_data *data)
{
	(void)data;
	free(data->textures.ea);
	free(data->textures.we);
	free(data->textures.so);
	free(data->textures.no);
	free(data->value);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data		data;
	char		**map;

	if (ac == 1 || ac > 2)
		return (printf("Error \n number of argm is invalide\n"), 1);
	data.value = ft_read_map(av[1]);
	if (!data.value)
		return (1);
	if (ft_check_value(data.value, &data.textures, &data.color))
		free_all(&data);
	if (ft_check_new_line(data.value))
		free_all(&data);
	map = ft_map(data.value);
	data.map = ft_new_map(map);
	if (!ft_check_map(data.map, 0, 0))
		return (free_all(&data), 1);
	ft_map_wall(&data, 0, 0);
	data.map_y = ft_lenmap(data.map);
	data.map_x = long_line(data.map);
	data.map_int = ft_to_int(data.map);
	data.id = 0;
	ft_front_of_player(&data);
	ft_virtualwall(&data);
	ft_window(data);
	ft_fre(map);
}
