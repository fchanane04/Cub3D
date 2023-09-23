/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:10:39 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/02 06:55:55 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

char	*compare_texture(char *content)
{
	if (!ft_strncmp(content, "NO", 2))
		return (ft_strdup("NO"));
	if (!ft_strncmp(content, "SO", 2))
		return (ft_strdup("SO"));
	if (!ft_strncmp(content, "WE", 2))
		return (ft_strdup("WE"));
	if (!ft_strncmp(content, "EA", 2))
		return (ft_strdup("EA"));
	return (NULL);
}

void	check_xpm(char *content, char **c, t_game **g, char **l)
{
	char	*ext;

	ext = ft_strrchr(content, '.');
	if (!ext || ft_strlen(ext) != 4)
		free_failed_config(g, l, c, VALID_TEXT_PATH);
	if (ft_strncmp(ext, ".xpm", 4))
		free_failed_config(g, l, c, VALID_TEXT_PATH);
}

void	check_valid_path(char *content, char **c, t_game **g, char **l)
{
	int	fd;

	fd = open(content, O_RDONLY);
	if (fd < 0)
		free_failed_config(g, l, c, TEXT_PATH);
	close(fd);
	check_xpm(content, c, g, l);
}

int	assign_texture(char *texture, char *direct, t_game **g)
{
	t_game	*aux;
	int		flag;

	aux = *g;
	flag = 0;
	if (!ft_strncmp(direct, "NO", 2))
		flag = assign_correct_texture(&aux->wall_nord, texture);
	if (!ft_strncmp(direct, "SO", 2))
		flag = assign_correct_texture(&aux->wall_sud, texture);
	if (!ft_strncmp(direct, "WE", 2))
		flag = assign_correct_texture(&aux->wall_west, texture);
	if (!ft_strncmp(direct, "EA", 2))
		flag = assign_correct_texture(&aux->wall_east, texture);
	return (flag);
}

void	textures_parameters(char **content, t_game **g, char **line)
{
	int		i;
	int		flag;
	char	*direct;
	char	*content_hold;

	content_hold = *content;
	flag = 1;
	direct = compare_texture(content_hold);
	if (!direct)
		free_failed_config(g, line, content, TEXT_DIR);
	i = 2;
	while (content_hold[i]
		&& (content_hold[i] == ' ' || content_hold[i] == '\t'))
		i++;
	if (!content_hold[i] || (i == 2))
	{
		free(direct);
		free_failed_config(g, line, content, TEXT_NO_PATH);
	}
	check_valid_path(&content_hold[i], content, g, line);
	flag = assign_texture(&content_hold[i], direct, g);
	free(direct);
	handle_texture_behavior(flag, content, g, line);
}
