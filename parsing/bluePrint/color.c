/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:55:44 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/04 23:11:23 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../parser.h"

int	count_words(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}

void	check_valid_number(char *color)
{
	int	i;
	int	number;

	i = 0;
	while (color[i] == '0')
		i++;
	if (ft_strlen(&color[i]) > 3)
		error_printer(NUM_RANGE);
	i = 0;
	while (color[i])
	{
		if (color[i] < '0' || color[i] > '9')
			error_printer(VALID_NUM);
		i++;
	}
	number = ft_atoi(color);
	if (number < 0 || number > 255)
		error_printer(NUM_RANGE);
}

void	check_numbers(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		check_valid_number(colors[i]);
		i++;
	}
}

int	check_color(char **colors)
{
	int	color;

	if (count_words(colors) != 3)
		error_printer(COLOR_ERR);
	check_numbers(colors);
	color = encode_color(0, ft_atoi(colors[0]),
			ft_atoi(colors[1]), ft_atoi(colors[2]));
	return (color);
}

void	colors_parameters(char **content, t_game **g, char **line)
{
	int		i;
	int		color;
	char	*content_hold;
	char	**colors;
	t_game	*aux;

	i = 1;
	aux = *g;
	content_hold = *content;
	if ((content_hold[0] == 'F' && aux->floor_color > -1)
		|| (content_hold[0] == 'C' && aux->ceiling_color > -1))
		free_failed_config(g, line, content, COLOR_DUP);
	while (content_hold[i]
		&& (content_hold[i] == ' ' || content_hold[i] == '\t'))
		i++;
	if (!content_hold[i] || !valid_splitter_count(&content_hold[i]))
		free_failed_config(g, line, content, COLOR_NOT_FOUND);
	colors = ft_split(&content_hold[i], ',');
	color = check_color(colors);
	leaks_hunter(&colors);
	assign_correct_color(content_hold[0], color,
		&aux->ceiling_color, &aux->floor_color);
}
