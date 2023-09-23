/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:32:57 by afaris            #+#    #+#             */
/*   Updated: 2023/04/04 23:13:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_it(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

int	game_over(t_game *g, char *err_msg)
{
	mlx_destroy_window(g->mlx, g->win);
	error_printer(err_msg);
	return (0);
}

int	refresh_screen(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	render_3d(g);
	render_map(g);
	key_hook_manager(g);
	return (0);
}
