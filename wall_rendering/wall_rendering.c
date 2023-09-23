/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:51:25 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/03 14:28:00 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_image	*create_screen_image(t_game *g)
{
	t_image	*image;
	int		i;
	int		j;

	i = 0;
	j = 0;
	image = malloc(sizeof(t_image));
	if (!image)
		game_over(g, MALLOC_ERROR);
	image->instance = mlx_new_image(g->mlx, SCREEN_MIN_WIDTH,
			SCREEN_MIN_HEIGHT);
	if (!image->instance)
	{
		free(image);
		game_over(g, IMAGE_ERR);
	}
	image->addr = mlx_get_data_addr(image->instance,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
	return (image);
}

t_text	*get_texture_image(t_game *g, char *img_path)
{
	t_text	*txt;

	txt = malloc(sizeof(t_text));
	if (!txt)
		game_over(g, MALLOC_ERROR);
	txt->img = mlx_xpm_file_to_image(g->mlx, img_path,
			&txt->width, &txt->height);
	if (!txt->img)
		error_printer(XPM_CONVERTION_ERR);
	txt->add = mlx_get_data_addr(txt->img, &(txt->bits_per_pixel),
			&(txt->line_length), &(txt->endian));
	return (txt);
}

int	get_texture_pixel(t_text *texture, int x, int y)
{
	char	*dst;

	dst = NULL;
	if (x >= 0 && x < MAP_CELL_SIZE && y >= 0 && y < MAP_CELL_SIZE)
	{
		dst = texture->add + \
			(y * texture->line_length + x * (texture->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	draw_3d_wall(double i, t_ray r, t_game *g, double st_ang)
{
	t_draw		d;
	int			j;

	d.cor_dist = r.distance * cos(st_ang - g->player->rotation_angle);
	d.dist_plane = (SCREEN_MIN_WIDTH / 2) / (tan(g->angle_of_vue / 2));
	d.wall_strip_height = (MAP_CELL_SIZE / d.cor_dist) * d.dist_plane;
	d.start_x = i;
	d.start_y = (SCREEN_MIN_HEIGHT / 2) - (d.wall_strip_height / 2);
	d.saver = d.wall_strip_height;
	d.offset_y = 0;
	reset_start_end(&d.start_y, &d.wall_strip_height, d.saver, &d.offset_y);
	d.end_point = d.start_y;
	d.offset_x = set_offset_x(r);
	d.txt = correct_texture(g, r.inter_dir, st_ang);
	j = 0;
	while (j++ < d.wall_strip_height)
	{
		d.fract_offset_y = d.offset_y * (MAP_CELL_SIZE / d.saver);
		put_pixel(g->screen_img, d.start_x, d.start_y,
			get_texture_pixel(d.txt, d.offset_x, d.fract_offset_y));
		d.offset_y++;
		d.start_y++;
	}
	ceiling_render(g, d);
	floor_render(g, d);
}

void	render_3d(t_game *g)
{
	t_ray	r;
	double	start_angle;
	double	i;

	i = g->rays_num - 1;
	start_angle = normalize_angle(g->player->rotation_angle
			- (g->angle_of_vue / 2));
	while (i)
	{
		cast_ray(g, start_angle, &r);
		if (r.distance == 0)
			r.distance = 1;
		draw_3d_wall(i, r, g, start_angle);
		start_angle = normalize_angle(start_angle + g->delta_angle);
		i--;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->screen_img->instance, 0, 0);
}
