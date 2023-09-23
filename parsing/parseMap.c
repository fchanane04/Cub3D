/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:01:46 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/04 23:12:33 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_map_components(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0' && (map[i + 1] && map[i + 1] == 13))
			return (0);
		if (map[i] != '1' && map[i] != '0' && map[i] != 13
			&& map[i] != '\n' && map[i] != 32 && !is_player_pos(map[i]))
			return (-1);
		i++;
	}
	return (1);
}

char	**fill_in_map(char *map, int map_height, int map_width)
{
	char	**maps;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	maps = malloc(sizeof(char *) * (map_height + 1));
	memory_alloc_fail_check(maps);
	while (i < map_height)
	{
		while (!(map[k] != 13 && map[k] != '\n'))
			k++;
		maps[i] = malloc(sizeof(char) * (map_width + 1) + 2);
		memory_alloc_fail_check_2(maps[i]);
		j = 0;
		while (map[k] && map[k] != 13 && map[k] != '\n')
			maps[i][j++] = map[k++];
		while (j < (map_width))
			maps[i][j++] = '#';
		maps[i++][j] = '\0';
		k++;
	}
	maps[i] = NULL;
	return (maps);
}

int	check_game_paths(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_open_space(map[i][j]))
			{
				if (j == 0 || j == (width - 1))
					return (0);
				else
				{
					if (i == 0 || i == (height - 1)
						|| !check_unvalid_paths(map, i, j))
						return (0);
				}
			}
			j++;
		}
	}
	return (1);
}

void	parse_map(char **map, t_game **g)
{
	t_game	*aux;

	aux = *g;
	if (!check_player(*map, g))
		free_unvalid_map(map, g, PLAYER_NUM_ERR);
	if (check_map_components(*map) == -1)
		free_unvalid_map(map, g, UNVALID_CHAR);
	if (check_map_components(*map) == 0)
		free_unvalid_map(map, g, UNVALID_MAP);
	aux->map = fill_in_map(*map, aux->map_height, aux->map_width);
	free(*map);
	if (!check_game_paths(aux->map, aux->map_height, aux->map_width))
		free_map_not_found(g, UNVALID_MAP);
}
