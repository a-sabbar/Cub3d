/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:16:53 by asabbar           #+#    #+#             */
/*   Updated: 2022/10/16 21:26:48 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>

# define W				10
# define N				20
# define S				30
# define E				40
# define TILE			16
# define W_WIDTH		1020
# define W_HEIGHT		720
# define FOFV			1.0471975512

typedef struct s_fr_elem{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_fr_elem;

typedef struct s_color{
	int		f[3];
	int		c[3];
}	t_color;

typedef struct s_textures{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	void	*img;
	int		**img_data;
	int		height[4];
	int		width[4];
}	t_textures;

typedef struct s_vector{
	double	x;
	double	y;
	bool	is_it_vertical;
}	t_vector;

typedef struct s_calc {
	int			h;
	int			v;
	double		dis_h;
	double		dis_v;
}				t_calc;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_player {
	t_vector	posi;
	double		x;
	double		y;
	double		radius;
	double		turndirection;
	double		waldirection;
	double		left_rightdirection;
	double		rotationangle;
	double		movespeed;
	double		rotationspeed;
}				t_player;

typedef struct s_data{
	void		*mlx;
	void		*mlx_win;
	char		*value;
	char		**map;
	int			**map_int;
	int			map_x;
	int			map_y;
	t_image		img;
	t_player	player;
	t_vector	mouse;
	bool		is_clicked;
	t_vector	posi_player;
	double		alpha;
	t_vector	rays[W_WIDTH];
	t_textures	textures;
	double		dis_rays[W_WIDTH];
	t_color		color;
	int			id;
	double		face;
	t_fr_elem	var;
}	t_data;

int			ft_check_textures(char *str, t_textures	*tx, int n);
int			ft_strncmp(char *str1, char *str2, int n);
char		**ft_split(char *s, char c);
int			ft_strcmp(char *str1, char *str2);
int			ft_check_is_xpm(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_read_map(char *file);
char		*ft_strchr(char *str, int c);
char		*get_next_line(int fd);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strdup(char *src);
size_t		ft_strlen(char *s);
int			ft_check_value(t_data *data, char *value, t_textures *tx, t_color *colors);
int			ft_atoi_color( char *str);
int			ft_isdigit(int c);
int			ft_ceilling(char *str, t_color *color);
int			ft_floor(char *str, t_color *color);
char		*ft_strtrim(char *s1, char *set);
char		**free_tab(char **tab);
char		*ft_strtrim1(char *s1, char *set);
void		ft_fre(char **cmd);
int			ft_check_map(char **map, int i, int j);
int			ft_check_new_line(char *value);
int			ft_lenmap(char **str);
int			mouse_movement(int x, int y, t_data *data);
int			button_release(int button, int x, int y, t_data *data);
int			button_press(int button, int x, int y, t_data *data);
int			key_hook(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
int			cross_x(t_data *data);
void		free_all(t_data *data);
void		get_textures(t_data *data);
void		ft_map_wall(t_data *data, int i, int j);
int			long_line(char **str);
int			**ft_to_int(char **map);
t_vector	ft_position_player(t_data data);
void		ft_draw_map(t_data data, int i, int j, t_image img);
void		ft_horizontal_calc(t_data data, t_vector *step_h, t_vector *a_h);
void		ft_vertical_calc(t_data data, t_vector	*step_v, t_vector	*a_v);
int			ft_check_vertical(t_data data, t_vector	*step_v, \
								t_vector *a_v, int *v);
int			ft_check_horizontal(t_data data, t_vector *step_h, \
								t_vector *a_h, int *h);
t_vector	ft_check_calc(t_data data, t_calc calc, t_vector a_h, t_vector a_v);
void		invalide_texture(void *img, t_data *data);
int			ft_atoi_map(char str);
char		**ft_new_map(char **oldmap);
char		**ft_map(char *value);
char		*ft_strrchr(char *s, int c);
int			ft_lenmap(char **str);
int			ft_rendering_wall(t_data *data);
t_vector	ft_len_of_line(t_data data);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		ft_draw_wall(t_data *data, int start, int len, double wall);
void		ft_fre2(int **cmd);
void		ft_ckeck_wall_up_down(t_data *data, double calc_x, double calc_y);
void		ft_ckeck_wall_left_right(t_data *data);
void		ft_ckeck_between_walls(t_data *data, double calc_x, double calc_y);
void		ft_raycasting_calc(t_data *data);
void		ft_front_of_player(t_data *data);
void		ft_virtualwall(t_data *data);
void		ft_draw_field_of_view(t_data *data);
void		ft_draw_player(t_image	img);
int			ft_draw(t_data *data);
int			ft_check_value_player(char *tmp, t_textures *tx, t_fr_elem *var);
void		ft_draw_background(int i, int j, t_image img);
int			ft_check_character(char **map, int i, int j, int *nb_player);
void		ft_value(t_fr_elem *var);
void		ft_draw_wall_minimap(t_data data, int i, int j, t_image img);
void		ft_draw_map(t_data data, int i, int j, t_image img);
void		ft_window(t_data data);
void		free_all(t_data *data);
int			find_color(t_data *data,
				double wall, double offset_x, int from_top);
int			find_color_2(t_data *data,
				double wall, double offset_x, int from_top);
void		ft_draw_wall(t_data *data, int start, int len, double wall);
int			create_rgb(int r, int g, int b);
void		ft_draw_floor(t_data *data, double start, double len);
void		ft_draw_ceiling(t_data *data, double start, double len);
int			ft_rendering_wall(t_data *data);
void		*malloc(size_t size);
int			ft_is_player(int x);
void		ft_front_of_player(t_data *data);
int			ft_check_is_close_condition(char **map, int i, int j);
int			ft_check_is_close(char **map, int i, int j);
void		*ft_malloc(int size);
#endif