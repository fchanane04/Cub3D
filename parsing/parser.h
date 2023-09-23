/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:14:44 by fchanane          #+#    #+#             */
/*   Updated: 2023/04/04 23:13:35 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cub3d.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

/************* error msgs ***************/
# define ARG_ERR "Number of arguments is not valid"
# define AV_ERR "File should have a name"
# define EXT_EMPTY "File should have an extention"
# define EXT_ERR "Unvalid extention"
# define FILE_ERR "Unvalid file, check if it exist"
# define XPM_ERR "Textures should have an extention"
# define TYPE_ERR "Unvalid extention"
# define EMP_PATH_ERR "Path is empty"
# define EMPTY_FILE "File is empty"
# define MAP_ERR "Map should not contain empty lines"
# define SETUP_ERR "Unvalid game settup"
# define MAP_NOT_FOUND "Map not found"
# define NOT_ENOUGH "Not enough game settup"
# define TEXT_DIR "Texture direction is not valid"
# define TEXT_PATH "Some texture path does not exist"
# define TEXT_NO_PATH "Texture has no path"
# define COLOR_NOT_FOUND "Color has no parameters or invalid ones"
# define COLOR_DUP "Color is already assigned!!"
# define VALID_NUM "Color parameters should be valid numbers"
# define PLAYER_NUM_ERR "More than one OR none player is present on the map"
# define PLAYER_NOT_FOUND "No player is present on the map"
# define NUM_RANGE "Unvalid range of number"
# define COLOR_ERR "unvalid parameters"
# define TEXT_ERR "Texture is already assigned"
# define VALID_TEXT_PATH "Not a valid path extention"
# define MALLOC_ERROR "Memory Allocation has been failed"
# define IMAGE_ERR "Unable to create a new image"
# define XPM_CONVERTION_ERR "Unable to convert this xpm to an image"
# define MLX_CONNECTION_ERR "Unable to setup graphical system connection"
# define WINDOW_ERR "Unable to create a new window"
# define UNVALID_CHAR "Unvalid character detected"
# define UNVALID_MAP "Unvalid map"

/************* libft ***************/
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
char	*ft_strrchr(char *s, int c);

/************* getNextline ***************/
int		search(char *s, int c);
char	*restart(char **stock);
char	*create_line(char **stock);
char	*stock_in(int fd, char *stock, char *rest, int rd);
char	*get_next_line(int fd);

/************* printer ***************/
void	msg_printer(char *msg);
void	error_printer(char *err);

/************* map errors ***************/
bool	is_open_space(char pos);
int		check_unvalid_paths(char **map, int i, int j);

/************* leaks hunter ***************/
void	unvalid_game(t_game **g);
void	free_failed_config(t_game **g, char **l, char **c, char *msg);
void	leaks_hunter(char ***table);
void	free_map_not_found(t_game **g, char *err_msg);
void	free_failed_map(char **line, t_game **g, char **map, char *err_msg);
void	free_unvalid_map(char **map, t_game **g, char *err_msg);

/************* primary checks ***************/
int		primary_checks(int ac, char *av);
void	arg_check(int ac, char *av);
void	ext_check(char *ext);
int		file_check(char *av);

/************* parse map utils ***************/
char	*create_map(char *map, char *line);
void	memory_alloc_fail_check(char **map);
void	memory_alloc_fail_check_2(char *map);
void	check_borderline(char *line);
int		check_player(char *map, t_game **g);

/************* parse utils ***************/
bool	empty_line(char *line);
void	parse_config(char *line, t_game **g);

/************* parse file ***************/
void	parse_file(int fd, t_game **g);
void	check_empty_file(char *line, t_game **g);

/************* color ***************/
int		encode_color(int t, int r, int g, int b);
int		count_words(char **table);
void	check_valid_number(char *color);
void	check_numbers(char **colors);
int		check_color(char **colors);
void	colors_parameters(char **content, t_game **g, char **line);
void	assign_correct_color(char dir, int color, int *ceiling, int *floor);
int		valid_splitter_count(char *content);

/************* texture ***************/
char	*compare_texture(char *content);
void	check_xpm(char *content, char **c, t_game **g, char **l);
void	check_valid_path(char *content, char **c, t_game **g, char **l);
void	textures_parameters(char **content, t_game **g, char **line);
int		assign_correct_texture(char **wall_dir, char *texture);
void	handle_texture_behavior(int flag, char **c, t_game **g, char **l);

/************* parse map ***************/
char	*create_map(char *map, char *line);
void	check_borderline(char *line);
void	parse_map(char **map, t_game **g);
void	init_config_data(t_game **g);

#endif
