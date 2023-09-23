/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapErrors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:22:02 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/01 14:46:04 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_open_space(char pos)
{
	if (pos == '0' || pos == 'N' || pos == 'W' || pos == 'S' || pos == 'E')
		return (true);
	return (false);
}

int	check_unvalid_paths(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' '
		|| map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (0);
	if (map[i][j - 1] == '#' || map[i][j + 1] == '#'
		|| map[i - 1][j] == '#' || map[i + 1][j] == '#')
		return (0);
	return (1);
}
