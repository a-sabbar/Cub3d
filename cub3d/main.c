/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:38:01 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/16 21:26:12 by youchenn         ###   ########.fr       */
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
			if (data.map[i][j] == 'N' || data.map[i][j] == 'S'
			|| data.map[i][j] == 'E' || data.map[i][j] == 'W')
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
	data.player.movespeed = 2;
	data.player.rotationspeed = 3 * (M_PI / 180);
	posi_player = ft_position_player(data);
	data.player.y = (posi_player.y) * TILE + TILE / 2;
	data.player.x = (posi_player.x) * TILE + TILE / 2;
	data.posi_player = posi_player;
	data.is_clicked = false;
	data.mouse.x = 0;
	mlx_hook(data.mlx_win, 2, 0L, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0L, cross_x, &data);
	mlx_hook(data.mlx_win, 3, 0L, key_release, &data);
	mlx_loop_hook(data.mlx, ft_draw, &data);
	mlx_loop(data.mlx);
}

void	free_all(t_data *data)
{
	(void)data;

	if(data->var.ea)
		free(data->textures.ea);
	if(data->var.we)
		free(data->textures.we);
	if(data->var.so)
		free(data->textures.so);
	if(data->var.no)
		free(data->textures.no);
	free(data->value);
	exit(1);
}

void f()
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_data		data;
	char		**map;

	atexit(f);
	if (ac == 1 || ac > 2)
		return (printf("Error \n number of argm is invalide\n"), 1);
	data.value = ft_read_map(av[1]);
	if (!data.value)
		return (1);
	if (ft_check_value(&data, data.value, &data.textures, &data.color))
		free_all(&data);
	if (ft_check_new_line(data.value))
		free_all(&data);
	map = ft_map(data.value);
	data.map = ft_new_map(map);
	ft_fre(map);
	if (!ft_check_map(data.map, 0, 0))
		return (free_all(&data), 1);
	ft_map_wall(&data, 0, 0);
	data.map_y = ft_lenmap(data.map);
	data.map_x = long_line(data.map);
	data.map_int = ft_to_int(data.map);
	data.id = 0;
	ft_front_of_player(&data);
	// ft_virtualwall(&data);






	//ziiiidha l bonus rah bonus mazal khasser
	
	ft_window(data);
}
