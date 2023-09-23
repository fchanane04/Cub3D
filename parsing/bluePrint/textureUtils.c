/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textureUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:28:26 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/02 06:56:24 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	assign_correct_texture(char **wall_dir, char *texture)
{
	if (*wall_dir)
		return (-1);
	*wall_dir = ft_strdup(texture);
	return (1);
}

void	handle_texture_behavior(int flag, char **c, t_game **g, char **l)
{
	if (flag == -1)
		free_failed_config(g, l, c, TEXT_ERR);
	if (flag == 0)
		free_failed_config(g, l, c, TEXT_DIR);
}
