/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:03:34 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 17:05:19 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall(t_game *g, int i, int j)
{
	if (i < 0 || i >= g->map_height)
		return (0);
	if (j < 0 || j >= g->map_width)
		return (0);
	if (g->map[i][j] == '1')
		return (1);
	return (0);
}

int	special_case(t_game *g, int i, int j)
{
	if (is_wall(g, i, j))
		return (1);
	if (angle_y_direction(g->player->rotation_angle) == SUD)
	{
		if (angle_x_direction(g->player->rotation_angle) == RIGHT)
			return (is_wall(g, i, j - 1) && is_wall(g, i - 1, j));
		else
			return (is_wall(g, i - 1, j) && is_wall(g, i, j + 1));
	}
	else
	{
		if (angle_x_direction(g->player->rotation_angle) == RIGHT)
			return (is_wall(g, i, j + 1) && is_wall(g, i - 1, j));
		else
			return (is_wall(g, i, j - 1) && is_wall(g, i - 1, j));
	}
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

void	textures_init(t_game *g)
{
	g->north_img = get_texture_image(g, g->wall_nord);
	g->sud_img = get_texture_image(g, g->wall_sud);
	g->east_img = get_texture_image(g, g->wall_east);
	g->west_img = get_texture_image(g, g->wall_west);
}
