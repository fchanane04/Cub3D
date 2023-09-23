/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:20:38 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/04 23:13:48 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	*g;

	g = NULL;
	g = malloc(sizeof(t_game));
	if (!g)
		game_over(g, MALLOC_ERROR);
	fd = primary_checks(ac, av[1]);
	init_config_data(&g);
	parse_file(fd, &g);
	game_init(g);
	mlx_loop_hook(g->mlx, refresh_screen, g);
	mlx_hook(g->win, ON_KEYDOWN, 0, key_press, g);
	mlx_hook(g->win, ON_KEYUP, 0, key_release, g);
	mlx_hook(g->win, ON_DESTROY, 0, game_over, g);
	mlx_loop(g->mlx);
	return (0);
}
