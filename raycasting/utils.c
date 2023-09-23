/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:48:10 by afaris            #+#    #+#             */
/*   Updated: 2023/03/27 23:48:20 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	is_in_wall(t_game *g, t_point p)
{
	int	i;
	int	j;

	i = p.y / MAP_CELL_SIZE;
	j = p.x / MAP_CELL_SIZE;
	if (i >= 0 && j >= 0 && i < g->map_height && j < g->map_width
		&& g->map[i][j] == '1')
		return (1);
	return (0);
}

double	get_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

int	angle_x_direction(double angle)
{
	if (angle >= degree_to_rad(90) && angle < degree_to_rad(270))
		return (LEFT);
	return (RIGHT);
}

int	angle_y_direction(double angle)
{
	if (angle >= 0 && angle < degree_to_rad(180))
		return (NORTH);
	return (SUD);
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle <= 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}
