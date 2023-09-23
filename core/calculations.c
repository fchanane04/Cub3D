/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:31:16 by afaris            #+#    #+#             */
/*   Updated: 2023/03/27 23:32:47 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

double	get_opposite(double angle, double hypotenuse)
{
	return (sin(angle) * hypotenuse);
}

double	get_adjacent(double angle, double hypotenuse)
{
	return (cos(angle) * hypotenuse);
}

double	get_hypoteneuse(double angle, double adjacent)
{
	return (adjacent / cos(angle));
}

double	degree_to_rad(double degree)
{
	return (degree * (M_PI / 180));
}
