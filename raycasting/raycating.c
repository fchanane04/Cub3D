/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:26 by afaris            #+#    #+#             */
/*   Updated: 2023/04/02 15:23:37 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	get_distance(t_point a, t_point b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

void	cast_ray(t_game *g, double angle, t_ray *ray)
{
	t_point	v_inter;
	t_point	h_inter;
	double	h_distance;
	double	v_distance;

	h_distance = 0;
	v_distance = 0;
	find_horizontal_intersection(g, angle, &h_inter);
	find_vertical_intersection(g, angle, &v_inter);
	h_distance = get_distance(h_inter, g->player->pos);
	v_distance = get_distance(v_inter, g->player->pos);
	ray->distance = get_min(h_distance, v_distance);
	if (ray->distance == h_distance)
	{
		ray->inter_dir = 'H';
		ray->inter_x = h_inter.x;
		ray->inter_y = h_inter.y;
	}
	else
	{
		ray->inter_dir = 'V';
		ray->inter_x = v_inter.x;
		ray->inter_y = v_inter.y;
	}
}
