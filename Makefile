NAME = cub3d.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

SRCS = main.c \
		core/hooks.c \
		core/movements.c \
		core/calculations.c \
		core/init.c \
		core/core.c \
		core/utils.c\
		parsing/printer.c\
		parsing/primaryChecks.c\
		parsing/libft/ft_strdup.c\
		parsing/libft/ft_strjoin.c\
		parsing/libft/ft_substr.c\
		parsing/libft/ft_strlen.c\
		parsing/libft/ft_strcmp.c\
		parsing/libft/ft_strchr.c\
		parsing/libft/ft_strrchr.c\
		parsing/libft/ft_strncmp.c\
		parsing/libft/ft_split.c\
		parsing/libft/ft_atoi.c\
		parsing/mapErrors.c\
		parsing/parseMapUtils.c\
		parsing/parseFile.c\
		parsing/parseMap.c\
		parsing/getNextline.c\
		parsing/parseUtils.c\
		parsing/bluePrint/color.c\
		parsing/bluePrint/colorUtils.c\
		parsing/bluePrint/textures.c\
		parsing/bluePrint/textureUtils.c\
		parsing/leaksHunter.c\
		parsing/leaksHunter2.c\
		parsing/inits.c\
		map/render.c\
		map/utils.c\
		map/pixels.c\
		map/extra_utils.c\
		raycasting/raycating.c\
		raycasting/vertical.c\
		raycasting/utils.c\
		raycasting/horizontal.c\
		raycasting/vertical.c\
		wall_rendering/wall_rendering.c\
		wall_rendering/rendering_colors.c\


OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -lmlx -framework OpenGL -framework AppKit -o cub3D

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf cub3D

re : fclean all

run : re
	@./cub3d files/file.cub

.PHONY: re fclean all clean