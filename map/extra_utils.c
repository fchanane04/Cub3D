/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:07:42 by afaris            #+#    #+#             */
/*   Updated: 2023/04/02 13:52:13 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_minimap_y_start(t_game *g)
{
	double	y;

	y = g->player->pos.y - ((MAP_MIN_HEIGHT / 2) * MAP_CELL_SIZE);
	if (y < 0)
		y = 0;
	return (y);
}

double	get_minimap_x_start(t_game *g)
{
	double	x;

	x = (g->player->pos.x) - ((MAP_MIN_WIDTH / 2) * MAP_CELL_SIZE);
	if (x < 0)
		x = 0;
	return (x);
}

int	is_floor(t_game *g, int x, int y)
{
	if (x < g->map_width && y < g->map_height)
		if (g->map[y][x] && g->map[y][x] == '0')
			return (1);
	return (0);
}

void	set_minimap_player_pos(t_game *g, double x, double y)
{
	g->player->minimap_pos.x = x;
	g->player->minimap_pos.y = y;
}
