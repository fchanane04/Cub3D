/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:58:08 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/02 06:58:26 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_RENDERING_H
# define WALL_RENDERING_H

void	render_3d(t_game *g);
t_text	*get_texture_image(t_game *g, char *img_path);
t_image	*create_screen_image(t_game *g);

#endif
