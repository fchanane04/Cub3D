/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:33:37 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 17:08:49 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_movement(t_game *g, double x, double y)
{
	int	i;
	int	j;

	i = y / MAP_CELL_SIZE;
	j = x / MAP_CELL_SIZE;
	if (i >= 0 && j >= 0 && i < g->map_height && j < g->map_width)
	{
		if (g->map[i][j] != '0')
			return (0);
	}
	else
		return (0);
	return (1);
}

void	turn_player(t_game *g, int key_code)
{
	if (key_code == RIGHT)
		g->player->rotation_angle += degree_to_rad(1 * ROTATION_SPEED);
	else if (key_code == LEFT)
		g->player->rotation_angle += degree_to_rad(-1 * ROTATION_SPEED);
	g->player->rotation_angle = normalize_angle(g->player->rotation_angle);
}

void	move_forward(t_game *g, double angle)
{
	t_point	next;

	next.y = g->player->pos.y - sin(angle) * PLAYER_SPEED;
	next.x = g->player->pos.x + cos(angle) * PLAYER_SPEED;
	if (valid_movement(g, next.x, next.y))
	{
		g->player->pos.x = next.x;
		g->player->pos.y = next.y;
	}
}

void	move_backward(t_game *g, double angle)
{
	t_point	next;

	next.y = g->player->pos.y - sin(angle) * -PLAYER_SPEED;
	next.x = g->player->pos.x + cos(angle) * -PLAYER_SPEED;
	if (valid_movement(g, next.x, next.y))
	{
		g->player->pos.x = next.x;
		g->player->pos.y = next.y;
	}
}

void	move_left_right(t_game *g, int key_code)
{
	double	tmp_angle;

	tmp_angle = 0;
	if (key_code == WEST)
	{
		tmp_angle = normalize_angle(g->player->rotation_angle + (M_PI / 2));
		move_forward(g, tmp_angle);
	}
	else
	{
		tmp_angle = normalize_angle(g->player->rotation_angle - (M_PI / 2));
		move_forward(g, tmp_angle);
	}
}
