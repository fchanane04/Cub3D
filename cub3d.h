/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:28:58 by afaris            #+#    #+#             */
/*   Updated: 2023/04/03 09:11:19 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "core/core.h"
# include "parsing/parser.h"
# include "map/map.h"
# include "raycasting/raycasting.h"
# include "wall_rendering/wall_rendering.h"

t_text		*get_texture_image(t_game *g, char *img_path);
int			get_texture_pixel(t_text *texture, int x, int y);
void		ceiling_render(t_game *g, t_draw draw);
void		floor_render(t_game *g, t_draw draw);
t_text		*correct_texture(t_game *g, char dir, double start_angle);
int			set_offset_x(t_ray r);
void		reset_start_end(double *s_y, double *stp, double sv, double *f_y);

#endif
