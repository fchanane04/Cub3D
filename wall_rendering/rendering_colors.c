/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:06:21 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/02 07:02:44 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ceiling_render(t_game *g, t_draw draw)
{
	int	i;

	i = 0;
	while (i < draw.end_point)
	{
		put_pixel(g->screen_img, draw.start_x, i, g->ceiling_color);
		i++;
	}
}

void	floor_render(t_game *g, t_draw draw)
{
	int	i;

	i = draw.start_y;
	while (i < SCREEN_MIN_HEIGHT)
	{
		put_pixel(g->screen_img, draw.start_x, i, g->floor_color);
		i++;
	}
}

t_text	*correct_texture(t_game *g, char dir, double start_angle)
{
	t_text	*txt;

	if (dir == 'V')
	{
		if (angle_x_direction(start_angle) == LEFT)
			txt = g->west_img;
		else
			txt = g->east_img;
	}
	else
	{
		if (angle_y_direction(start_angle) == NORTH)
			txt = g->north_img;
		else
			txt = g->sud_img;
	}
	return (txt);
}

int	set_offset_x(t_ray r)
{
	int	offset_x;

	if (r.inter_dir == 'V')
		offset_x = (int)r.inter_y % MAP_CELL_SIZE;
	else
		offset_x = (int)r.inter_x % MAP_CELL_SIZE;
	return (offset_x);
}

void	reset_start_end(double *s_y, double *stp, double sv, double *f_y)
{
	double	start;
	double	end;

	start = *s_y;
	end = *stp;
	if (start < 0)
	{
		*s_y = 0;
		*stp = SCREEN_MIN_HEIGHT;
	}
	if (sv > *stp)
		*f_y = (sv - SCREEN_MIN_HEIGHT) / 2;
}
