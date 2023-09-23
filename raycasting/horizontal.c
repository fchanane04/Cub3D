/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:46:34 by afaris            #+#    #+#             */
/*   Updated: 2023/03/28 13:31:37 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_horizontal_start(t_game *g, double angle, t_point *start)
{
	if (angle_y_direction(angle) == NORTH)
		start->y = floor(g->player->pos.y / MAP_CELL_SIZE) * MAP_CELL_SIZE;
	else
		start->y = floor(g->player->pos.y / MAP_CELL_SIZE) * MAP_CELL_SIZE
			+ MAP_CELL_SIZE;
	start->x = g->player->pos.x + (g->player->pos.y - start->y) / tan(angle);
}

void	set_horizontal_step(double angle, t_point *step)
{
	if (angle_y_direction(angle) == NORTH)
		step->y = -MAP_CELL_SIZE;
	else
		step->y = MAP_CELL_SIZE;
	step->x = MAP_CELL_SIZE / tan(angle);
	if (angle_y_direction(angle) == SUD)
		step->x *= -1;
}

void	find_horizontal_intersection(t_game *g, double angle, t_point *hpt)
{
	t_point	start;
	t_point	step;
	t_point	check;

	set_horizontal_start(g, angle, &start);
	set_horizontal_step(angle, &step);
	while (start.x >= 0 && start.x <= g->win_width && start.y >= 0
		&& start.y <= g->win_height)
	{
		check.x = start.x;
		check.y = start.y;
		if (angle_y_direction(angle) == NORTH)
			check.y -= 1;
		if (is_in_wall(g, check))
			break ;
		start.x += step.x;
		start.y += step.y;
	}
	hpt->x = start.x;
	hpt->y = start.y;
}
