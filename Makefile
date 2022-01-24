# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbronwyn <sbronwyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 15:58:22 by zcris             #+#    #+#              #
#    Updated: 2022/01/19 15:59:09 by sbronwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3D

SRC_FOLDER = srcs/mandatory/
SRC_BONUS_FOLDER = srcs/bonus/
HEADER_FOLDER = includes/
LIBFT_FOLDER = libft/

SRC_LIST = \
	struct/_color.c \
	struct/_coords.c \
	struct/_game.c \
	struct/_checklist.c \
	struct/_map_object.c \
	struct/_map.c \
	struct/_mlx_img.c \
	struct/_player.c \
	struct/_texture.c \
	struct/_z_array.c \
	errors/errors.c \
	map_parser/map_parser.c \
	map_parser/map_tests.c \
	utils/utls.c \
	utils/utls_color.c \
	utils/utls_mlx.c \
	utils/utls_gnl.c \
	utils/utls_map.c \
	utils/utls_map_test.c \
	utils/utls_cast.c \
	utils/utls_array.c \
	utils/utls_ray.c \
	stage/keyboard.c \
	stage/routine.c \
	stage/output.c \
	main.c

SRC_BONUS_LIST=$(SRC_LIST) \
	struct/_door.c \
	struct/_minimap.c \
	stage/mouse.c \
	stage/door.c \

LIBFT = $(LIBFT_FOLDER)libft.a

HEADER_LIST = \
	cub3D.h \
	errors.h

SRCS = $(addprefix $(SRC_FOLDER), $(SRC_LIST))
SRCS_BONUS = $(addprefix $(SRC_BONUS_FOLDER), $(SRC_BONUS_LIST))
HEADERS = $(addprefix $(HEADER_FOLDER), $(HEADER_LIST))

OTHER_DEPEND = Makefile

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

MLX_FOLDER=mlx/

ALL_LIBS	= \
	-L $(MLX_FOLDER) -lmlx -framework OpenGL -framework AppKit \
	-L $(LIBFT_FOLDER) -lft

ALL_HEADERS = \
	-I $(LIBFT_FOLDER)includes \
	-I $(HEADER_FOLDER) \
	-I $(MLX_FOLDER)

all:	$(NAME)

bonus:
	@make "SRCS=$(SRCS_BONUS)"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(ALL_HEADERS) -c $< -o $@

$(NAME):	$(LIBFT) $(OTHER_DEPEND) $(OBJS) $(HEADERS) 
	$(CC) $(CFLAGS) $(OBJS) $(ALL_LIBS) $(ALL_HEADERS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_FOLDER)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT_FOLDER) clean

fclean:	clean
	$(RM) $(NAME)
	@make -C $(LIBFT_FOLDER) fclean

re:	fclean $(NAME)

.PHONY:	all clean fclean re