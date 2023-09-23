/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:25:10 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 14:45:29 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 53
# define CLOSE 0
# define LEFT 124
# define RIGHT 123
# define NORTH 13
# define SUD 1
# define WEST 0
# define EST 2

# define SCREEN_MIN_WIDTH 1280
# define SCREEN_MIN_HEIGHT 720

# define MAP_MIN_WIDTH 32
# define MAP_MIN_HEIGHT 16

# define MAP_CELL_SIZE 32
# define MAP_PLAYER_SIZE 24

# define PLAYER_SPEED 4
# define ROTATION_SPEED 2

# define MINIMAP_SIZE 0.25

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct parser_s
{
	char	*line;
	int		stopper;
	char	*map;
}	t_parser;

typedef struct ray_s
{
	double	inter_x;
	double	inter_y;
	double	distance;
	char	inter_dir;
}			t_ray;

typedef struct point_s
{
	double		x;
	double		y;
}			t_point;

typedef struct image_s
{
	void		*instance;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

}			t_image;

typedef struct player_s
{
	t_point			pos;
	t_point			minimap_pos;
	double			rotation_angle;
	int				move[3];
}			t_player;

typedef struct s_text
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_text;

typedef struct draw_s
{
	double		dist_plane;
	double		wall_strip_height;
	double		start_x;
	double		start_y;
	double		cor_dist;
	double		end_point;
	double		offset_x;
	double		offset_y;
	double		fract_offset_y;
	double		saver;
	t_text		*txt;
}	t_draw;

typedef struct game_s
{
	void			*mlx;
	void			*win;
	char			**map;
	char			*wall_east;
	char			*wall_sud;
	char			*wall_west;
	char			*wall_nord;
	int				map_height;
	int				map_width;
	int				win_height;
	int				win_width;
	int				player_direction;
	int				floor_color;
	int				ceiling_color;
	int				rays_num;
	t_image			*screen_img;
	t_image			*minimap_img;
	t_text			*north_img;
	t_text			*sud_img;
	t_text			*east_img;
	t_text			*west_img;
	double			angle_of_vue;
	double			delta_angle;
	t_player		*player;
}			t_game;

int			key_press(int key_code, t_game *g);
int			key_release(int key_code, t_game *g);
int			refresh_screen(t_game *g);
void		key_hook_manager(t_game *g);

double		get_opposite(double angle, double hypotenuse);
double		get_adjacent(double angle, double hypotenuse);
double		degree_to_rad(double degree);
double		get_hypoteneuse(double angle, double adjacent);

int			valid_movement(t_game *g, double x, double y);
void		turn_player(t_game *g, int key_code);
void		move_forward(t_game *g, double angle);
void		move_backward(t_game *g, double angle);
void		move_left_right(t_game *g, int key_code);

void		game_init(t_game *g);
int			game_over(t_game *g, char *err_msg);
void		free_it(void *ptr);
int			is_player(char c);
void		textures_init(t_game *g);

#endif