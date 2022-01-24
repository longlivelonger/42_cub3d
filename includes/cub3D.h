/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:30:34 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 16:31:26 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "./errors.h"

# define WIDTH						800
# define HEIGHT						600
# define SOLID_COLOR_TEXTURE_WIDTH	64
# define SOLID_COLOR_TEXTURE_HEIGHT	64
# define MINIMAP_TEXTURE_WIDTH		8
# define MINIMAP_TEXTURE_HEIGHT		8
# define MINIMAP_POSITION_X			10
# define MINIMAP_POSITION_Y			10
# define MINIMAP_COLOR_FLOOR		"32,32,32"
# define MINIMAP_COLOR_WALL			"255,0,0"
# define MINIMAP_COLOR_PLAYER		"255,183,0"
# define MINIMAP_COLOR_FOV			"255,244,79"
# define MINIMAP_COLOR_DOOR			"0,0,255"
# define TITLE						"CUB3D"
# define RAY_COUNT					800
# define MAX_DEPTH					12
# define BUFFER_SIZE_GNL 			1024
# define PI							3.141592653589793

# define MOVEMENT_ROTATION_STEP		0.1
# define MOVEMENT_STEP_MULTIPLIER	0.15
# define DOOR_FRAME_COUNT			13

typedef struct s_coords
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}	t_coords;

typedef struct z_array_tag
{
	size_t		size;
	int			status;
	char		**elem;
}	t_z_array;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}	t_color;

typedef struct s_mlx_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_mlx_img;

typedef struct s_texture
{
	char		*file_path;
	t_color		*bgcolor;
	t_mlx_img	*mlx_img;
}	t_texture;

typedef struct s_door
{
	t_texture	*frames[DOOR_FRAME_COUNT];
	int			current_frame;
}	t_door;

typedef struct s_map_object
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
}	t_map_object;

typedef struct s_checklist
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_checklist;

typedef struct s_player
{
	t_coords	*coords;
}	t_player;

typedef struct s_map
{
	t_texture		*floor;
	t_texture		*celling;
	t_map_object	*wall;
	t_door			*door;
	t_z_array		*field;
}	t_map;

typedef struct s_minimap
{
	t_texture		*wall;
	t_texture		*floor;
	t_texture		*player;
	t_color			*fov_color;
	t_color			*door_color;
}	t_minimap;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_minimap	*minimap;
	t_player	*player;
	t_checklist	checklist;
}	t_game;

typedef struct s_raycast_result
{
	int		ray_number;
	float	x_detect;
	float	y_detect;
	int		nsew;
	int		x_texture_position;
	float	distant;
	float	angle;
}	t_raycast_result;

t_color			*color_c(int red, int green, int blue);
void			color_d(t_color *color);
int				str_to_color(t_color *color, const char *str);

t_z_array		*z_array_c(void);
void			z_array_d(t_z_array *z_array);
int				z_array_init(t_z_array *a);
int				z_array_append(t_z_array *a, char *str);
int				z_array_remove(t_z_array *a, size_t index);
int				z_array_free(t_z_array *a);

t_mlx_img		*mlx_img_c(void);
void			mlx_img_d(t_mlx_img *mlx_img);
void			mlx_img_create_addrs(t_mlx_img *t);

t_texture		*texture_c(void);
void			texture_d(t_texture *t);
int				texture_set_file(t_texture *t, const char *file_path);
void			texture_set_array_of_files(t_door *d,
					const char *file_path, int count);

t_door			*door_c(void);
void			door_d(t_door *door);

t_map_object	*map_object_c(void);
void			map_object_d(t_map_object *map_object);

t_minimap		*minimap_c(void);
void			minimap_d(t_minimap *minimap);
void			minimap_print_on_screen(t_game *game, t_mlx_img *mlximg);
void			minimap_print_player_fov(t_game *game, t_mlx_img *mlximg);

t_map			*map_c(void);
void			map_d(t_map *map);

t_coords		*coords_c(void);
void			coords_d(t_coords *coords);

t_player		*player_c(void);
void			player_d(t_player *player);
void			player_into_minimap(t_game *game, t_mlx_img *mlximg);

t_game			*game_c(void);
void			game_d(t_game *game);
int				game_close(void);
void			game_create_textures(t_game *game);

void			checklist_init(t_game *game);
int				checklist_is_complete(t_game *game);

int				routine_start(t_game *game);
void			routine_end(t_game *game);

int				keyboard_key_hook(int keycode, t_game *game);
int				map_parser(t_game *game, char *filename);

void			set_mouse_hook(t_game *game);
void			unset_mouse_hook(t_game *game);

void			errors_print(char *str);
void			errors_print_ln(char *str);

void			*utls_malloc(int size, int count);
void			utls_free(void *p);
float			utls_fabs_sub(float a, float b);

int				utls_color_to_int(t_color c);

void			utls_mlx_pixel_put(t_mlx_img *t, int x, int y, t_color color);
void			utls_mlx_pixel_t_put(t_mlx_img *t, int x, int y,
					unsigned int pix);
unsigned int	utls_mlx_pixel_get_ys(t_mlx_img *t, int x, int y);
void			utls_mlx_create_solid_image(t_game *game, t_texture *t);
void			utls_mlx_image_put(t_mlx_img *t, int x, int y, t_mlx_img *s);

char			*utls_gnl(int fd);

int				utls_array_append(char ***arr, char **str, int ind);
void			utls_array_free(char ***arr);

void			utls_adjust_map_width(t_game *game);

void			utls_ray_differ(t_game *game, t_raycast_result *r,
					float o_x, float o_y);
void			utls_ray_result(t_game *game, t_raycast_result *r);

float			get_angle(t_game *game, char direction);
t_coords		utls_next_cell(t_game *game, char direction);

int				map_parser_get_player_position(t_game *game);

int				map_tests_check(t_game *game);
int				map_tests_is_cub(char *filename);
int				map_tests_is_valid_char(char c);
int				map_is_surrounded(t_game *game);
int				map_is_good_content(t_game *game);

void			output_horizont(t_game *game, t_mlx_img *mlximg);
void			output_full_redraw(t_game *game);

void			output_print_walls(t_game *game, t_mlx_img *mlximg);

void			toggle_door(t_game *game, float x, float y);
int				is_empty(char c);
int				is_door(t_game *game, t_raycast_result *r);
int				is_no_door_textures(t_game *game);

#endif