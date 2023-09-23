/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMapUtils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:09:38 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/03 16:02:35 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*create_map(char *map, char *line)
{
	char	*join;

	join = ft_strjoin(map, line);
	return (join);
}

void	memory_alloc_fail_check(char **map)
{
	if (!map)
		error_printer("Memory allocation has been failed");
}

void	memory_alloc_fail_check_2(char *map)
{
	if (!map)
		error_printer("Memory allocation has been failed");
}

void	check_borderline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '#')
			error_printer("A wall is not closed!!");
		i++;
	}
}

int	check_player(char *map, t_game **g)
{
	int		i;
	int		counter;
	t_game	*aux;

	i = 0;
	counter = 0;
	aux = *g;
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'W' || map[i] == 'S' || map[i] == 'E')
			counter++;
		if (map[i] == 'N')
			aux->player_direction = 13;
		if (map[i] == 'W')
			aux->player_direction = 0;
		if (map[i] == 'S')
			aux->player_direction = 1;
		if (map[i] == 'E')
			aux->player_direction = 2;
		i++;
	}
	if (counter > 1 || aux->player_direction == -1)
		return (0);
	return (1);
}
