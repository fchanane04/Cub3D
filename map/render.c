/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:40:06 by afaris            #+#    #+#             */
/*   Updated: 2023/04/02 15:24:43 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_minimap_pos(double x, double y)
{
	x *= MINIMAP_SIZE;
	y *= MINIMAP_SIZE;
	if (x >= 0 && x < MAP_MIN_WIDTH * MAP_CELL_SIZE
		&& y >= 0 && y < MAP_MIN_HEIGHT * MAP_CELL_SIZE)
		return (1);
	return (0);
}

void	draw_player_direction(t_game *g)
{
	int		i;
	t_point	p;

	i = 0;
	p.x = g->player->minimap_pos.x;
	p.y = g->player->minimap_pos.y;
	while (i <= 100)
	{
		p.x = get_adjacent(g->player->rotation_angle, i);
		p.y = get_opposite(g->player->rotation_angle, i);
		if (valid_minimap_pos(g->player->minimap_pos.x + p.x,
				g->player->minimap_pos.y - p.y))
		{
			put_pixel(g->minimap_img,
				(g->player->minimap_pos.x + p.x) * MINIMAP_SIZE,
				(g->player->minimap_pos.y - p.y) * MINIMAP_SIZE, 0xFFF);
		}
		i++;
	}
}

void	put_player_pixels(t_game *g)
{
	int		i;
	int		j;
	t_point	p;

	p.y = g->player->minimap_pos.y - MAP_PLAYER_SIZE / 2;
	i = 0;
	j = 0;
	while (i < MAP_PLAYER_SIZE)
	{
		p.x = g->player->minimap_pos.x - MAP_PLAYER_SIZE / 2;
		while (j < MAP_PLAYER_SIZE)
		{
			put_pixel(g->minimap_img,
				p.x * MINIMAP_SIZE, p.y * MINIMAP_SIZE, 0xFFF);
			p.x++;
			j++;
		}
		p.y++;
		j = 0;
		i++;
	}
}

void	draw_map(t_game *g)
{
	double		i;
	double		j;
	t_point		p;

	i = 0;
	j = 0;
	p.y = get_minimap_y_start(g);
	while (i < MAP_MIN_HEIGHT * MAP_CELL_SIZE)
	{
		p.x = get_minimap_x_start(g);
		while (j < MAP_MIN_WIDTH * MAP_CELL_SIZE)
		{
			put_pixel_to_minimap(g, j, i, 0x262A56);
			if (!is_in_wall(g, p))
				put_pixel_to_minimap(g, j, i, 0xE3CCAE);
			if ((int)p.x == (int)g->player->pos.x
				&& (int)p.y == (int)g->player->pos.y)
				set_minimap_player_pos(g, j, i);
			j++;
			p.x++;
		}
		j = 0;
		p.y++;
		i++;
	}
}

void	render_map(t_game *g)
{
	draw_map(g);
	put_player_pixels(g);
	draw_player_direction(g);
	mlx_put_image_to_window(g->mlx, g->win, g->minimap_img->instance, 0, 0);
}
