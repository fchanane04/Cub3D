/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:14:24 by afaris            #+#    #+#             */
/*   Updated: 2023/04/02 13:52:33 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_wall_pixels(t_game *g, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	x *= MAP_CELL_SIZE * MINIMAP_SIZE;
	y *= MAP_CELL_SIZE * MINIMAP_SIZE;
	while (i < MAP_CELL_SIZE * MINIMAP_SIZE)
	{
		while (j < MAP_CELL_SIZE * MINIMAP_SIZE)
		{
			put_pixel(g->minimap_img, x + j, y + i, 0x262A56);
			j++;
		}
		j = 0;
		i++;
	}
}

void	put_floor_pixels(t_game *g, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	x *= MAP_CELL_SIZE * MINIMAP_SIZE;
	y *= MAP_CELL_SIZE * MINIMAP_SIZE;
	while (i < MAP_CELL_SIZE * MINIMAP_SIZE)
	{
		while (j < MAP_CELL_SIZE * MINIMAP_SIZE)
		{
			put_pixel(g->minimap_img, x + j, y + i, 0xE3CCAE);
			j++;
		}
		j = 0;
		i++;
	}
}
