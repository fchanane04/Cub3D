/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:39:20 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 14:24:26 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../cub3d.h"

void			put_pixel(t_image *image, int x, int y, int color);
void			render_map(t_game *g);
void			draw_line(t_game *g, double angle, double distance);
int				get_player_y_pos(t_game *g);
int				get_player_x_pos(t_game *g);
double			get_minimap_y_start(t_game *g);
double			get_minimap_x_start(t_game *g);
int				is_floor(t_game *g, int x, int y);
void			set_minimap_player_pos(t_game *g, double x, double y);
void			put_wall_pixels(t_game *g, int x, int y);
void			put_floor_pixels(t_game *g, int x, int y);
int				is_wall(t_game *g, int i, int j);
int				special_case(t_game *g, int i, int j);
void			put_pixel_to_minimap(t_game *g, int x, int y, int color);

#endif