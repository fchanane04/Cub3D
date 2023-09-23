/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:48:29 by afaris            #+#    #+#             */
/*   Updated: 2023/04/04 23:11:38 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_vertical_start(t_game *g, double angle, t_point *start)
{
	if (angle_x_direction(angle) == RIGHT)
		start->x = floor(g->player->pos.x / MAP_CELL_SIZE) * MAP_CELL_SIZE
			+ MAP_CELL_SIZE;
	else
		start->x = floor(g->player->pos.x / MAP_CELL_SIZE) * MAP_CELL_SIZE;
	start->y = g->player->pos.y + (g->player->pos.x - start->x) * tan(angle);
}

void	set_vertical_step(double angle, t_point *step)
{
	if (angle_x_direction(angle) == RIGHT)
		step->x = MAP_CELL_SIZE;
	else
		step->x = -MAP_CELL_SIZE;
	step->y = MAP_CELL_SIZE * tan(angle);
	if (angle_x_direction(angle) == RIGHT)
		step->y *= -1;
}

void	find_vertical_intersection(t_game *g, double angle, t_point *vpt)
{
	t_point	start;
	t_point	step;
	t_point	check;

	set_vertical_start(g, angle, &start);
	set_vertical_step(angle, &step);
	while (start.x >= 0 && start.x <= g->win_width && start.y >= 0
		&& start.y <= g->win_height)
	{
		check.x = start.x;
		check.y = start.y;
		if (angle_x_direction(angle) == LEFT)
			check.x -= 1;
		if (is_in_wall(g, check))
			break ;
		start.x += step.x;
		start.y += step.y;
	}
	vpt->x = start.x;
	vpt->y = start.y;
}
