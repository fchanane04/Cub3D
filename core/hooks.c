/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:33:23 by afaris            #+#    #+#             */
/*   Updated: 2023/04/04 23:15:28 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key_code, t_game *g)
{
	if (key_code == ESC)
		game_over(g, NULL);
	if (key_code == NORTH || key_code == SUD)
		g->player->move[0] = key_code;
	if (key_code == EST || key_code == WEST)
		g->player->move[1] = key_code;
	if (key_code == LEFT || key_code == RIGHT)
		g->player->move[2] = key_code;
	return (0);
}

int	key_release(int key_code, t_game *g)
{
	if (key_code == NORTH || key_code == SUD)
		g->player->move[0] = -1;
	if (key_code == EST || key_code == WEST)
		g->player->move[1] = -1;
	if (key_code == LEFT || key_code == RIGHT)
		g->player->move[2] = -1;
	return (0);
}

void	key_hook_manager(t_game *g)
{
	if (g->player->move[0] == NORTH)
		move_forward(g, g->player->rotation_angle);
	else if (g->player->move[0] == SUD)
		move_backward(g, g->player->rotation_angle);
	if (g->player->move[1] == EST || g->player->move[1] == WEST)
		move_left_right(g, g->player->move[1]);
	if (g->player->move[2] == LEFT || g->player->move[2] == RIGHT)
		turn_player(g, g->player->move[2]);
}
