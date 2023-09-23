/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaksHunter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:54:10 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/02 15:23:00 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	unvalid_game(t_game **g)
{
	t_game	*aux;

	aux = *g;
	if (aux->wall_east)
		free(aux->wall_east);
	if (aux->wall_sud)
		free(aux->wall_sud);
	if (aux->wall_west)
		free(aux->wall_west);
	if (aux->wall_nord)
		free(aux->wall_nord);
	leaks_hunter(&aux->map);
	free(*g);
}

void	free_failed_config(t_game **g, char **l, char **c, char *msg)
{
	free(*c);
	free(*l);
	unvalid_game(g);
	error_printer(msg);
}

void	free_map_not_found(t_game **g, char *err_msg)
{
	unvalid_game(g);
	error_printer(err_msg);
}

void	free_failed_map(char **line, t_game **g, char **map, char *err_msg)
{
	free(*line);
	free(*map);
	unvalid_game(g);
	error_printer(err_msg);
}

void	free_unvalid_map(char **map, t_game **g, char *err_msg)
{
	free(*map);
	unvalid_game(g);
	error_printer(err_msg);
}
