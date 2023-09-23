/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:43:33 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 14:24:22 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || y <= 0 || y > SCREEN_MIN_HEIGHT || x > SCREEN_MIN_WIDTH)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

int	get_player_y_pos(t_game *g)
{
	return (g->player->pos.y / MAP_CELL_SIZE);
}

int	get_player_x_pos(t_game *g)
{
	return (g->player->pos.x / MAP_CELL_SIZE);
}

void	put_pixel_to_minimap(t_game *g, int x, int y, int color)
{
	put_pixel(g->minimap_img, x * MINIMAP_SIZE, y * MINIMAP_SIZE, color);
}
