/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:41:35 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/04 23:11:12 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_empty_file(char *line, t_game **g)
{
	if (!line)
	{
		unvalid_game(g);
		error_printer(EMPTY_FILE);
	}
}

void	handle_config_error(int stopper, t_game **g, char **line)
{
	if (stopper == 0)
	{
		unvalid_game(g);
		free(*line);
		error_printer(EMPTY_FILE);
	}
	if (stopper && stopper < 6)
	{
		unvalid_game(g);
		free(*line);
		error_printer(NOT_ENOUGH);
	}
}

char	*merge_map(t_game **g, int fd, char *line)
{
	t_game	*aux;
	char	*map;

	aux = *g;
	map = ft_strdup("");
	while (line)
	{
		if ((ft_strlen(line) - 2) > aux->map_width)
			aux->map_width = ft_strlen(line) - 2;
		if (empty_line(line))
			free_failed_map(&line, g, &map, MAP_ERR);
		aux->map_height++;
		map = create_map(map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

char	*free_and_read(char **line, int fd)
{
	char	*tmp;

	tmp = *line;
	free(*line);
	tmp = get_next_line(fd);
	return (tmp);
}

void	parse_file(int fd, t_game **g)
{
	t_parser	parser;

	parser.line = get_next_line(fd);
	parser.stopper = 0;
	check_empty_file(parser.line, g);
	while (parser.line && (parser.stopper < 6))
	{
		if (!empty_line(parser.line))
		{
			parse_config(parser.line, g);
			parser.stopper++;
		}
		parser.line = free_and_read(&parser.line, fd);
	}
	handle_config_error(parser.stopper, g, &parser.line);
	if (parser.line)
	{
		while (parser.line && empty_line(parser.line))
			parser.line = free_and_read(&parser.line, fd);
	}
	if (!parser.line)
		free_map_not_found(g, MAP_NOT_FOUND);
	parser.map = merge_map(g, fd, parser.line);
	parse_map(&parser.map, g);
}
