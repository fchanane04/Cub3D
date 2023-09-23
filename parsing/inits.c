/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:15:55 by fchanane          #+#    #+#             */
/*   Updated: 2023/03/30 21:15:57 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_config_data(t_game **g)
{
	t_game	*aux;

	aux = *g;
	aux->wall_east = NULL;
	aux->sud_img = NULL;
	aux->north_img = NULL;
	aux->screen_img = NULL;
	aux->minimap_img = NULL;
	aux->east_img = NULL;
	aux->west_img = NULL;
	aux->wall_sud = NULL;
	aux->wall_west = NULL;
	aux->wall_nord = NULL;
	aux->floor_color = -1;
	aux->ceiling_color = -1;
	aux->map_height = 0;
	aux->map_width = 0;
	aux->player_direction = -1;
	aux->map = NULL;
}
