/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:18 by afaris            #+#    #+#             */
/*   Updated: 2023/04/02 15:23:19 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

int		is_in_wall(t_game *g, t_point p);
void	find_horizontal_intersection(t_game *g, double angle, t_point *hpt);
void	find_vertical_intersection(t_game *g, double angle, t_point *vpt);

double	get_min(double a, double b);
int		angle_x_direction(double angle);

int		angle_y_direction(double angle);
double	normalize_angle(double angle);
void	cast_ray(t_game *g, double angle, t_ray *ray);

#endif