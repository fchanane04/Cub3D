/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:28:38 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 14:31:24 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	setup_player_direction(t_game *g)
{
	if (g->player_direction == SUD)
		return (degree_to_rad(270));
	else if (g->player_direction == WEST)
		return (degree_to_rad(180));
	else if (g->player_direction == EST)
		return (degree_to_rad(0));
	return (degree_to_rad(90));
}

void	set_player_pos(t_game *g, double *x, double *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map[i])
	{
		while (g->map[i][j])
		{
			if (is_player(g->map[i][j]))
			{
				*x = (j * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2);
				*y = (i * MAP_CELL_SIZE) + (MAP_CELL_SIZE / 2);
				g->map[i][j] = '0';
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

t_player	*player_init(t_game *g)
{
	t_player	*p;

	p = malloc(sizeof(t_player));
	if (!p)
		game_over(g, MALLOC_ERROR);
	p->rotation_angle = setup_player_direction(g);
	set_player_pos(g, &p->pos.x, &p->pos.y);
	return (p);
}

t_image	*create_minimap_screen(t_game *g)
{
	t_image	*image;
	int		i;
	int		j;

	i = 0;
	j = 0;
	image = malloc(sizeof(t_image));
	if (!image)
		game_over(g, MALLOC_ERROR);
	image->instance = mlx_new_image(g->mlx,
			MAP_MIN_WIDTH * MAP_CELL_SIZE * MINIMAP_SIZE,
			MAP_MIN_HEIGHT * MAP_CELL_SIZE * MINIMAP_SIZE);
	if (!image->instance)
	{
		free(image);
		game_over(g, IMAGE_ERR);
	}
	image->addr = mlx_get_data_addr(image->instance,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
	return (image);
}

void	game_init(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		game_over(g, MLX_CONNECTION_ERR);
	g->win_height = g->map_height * MAP_CELL_SIZE;
	g->win_width = g->map_width * MAP_CELL_SIZE;
	g->win = mlx_new_window(g->mlx,
			SCREEN_MIN_WIDTH, SCREEN_MIN_HEIGHT, "cub3D");
	if (!g->win)
		game_over(g, WINDOW_ERR);
	g->player = player_init(g);
	g->rays_num = SCREEN_MIN_WIDTH;
	g->angle_of_vue = degree_to_rad(60);
	textures_init(g);
	g->delta_angle = g->angle_of_vue / g->rays_num;
	g->player->move[0] = -1;
	g->player->move[1] = -1;
	g->player->move[2] = -1;
	g->screen_img = create_screen_image(g);
	g->minimap_img = create_minimap_screen(g);
}
