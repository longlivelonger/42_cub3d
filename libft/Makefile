# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 07:59:34 by zcris             #+#    #+#              #
#    Updated: 2022/01/17 15:56:02 by sbronwyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

SRC_FOLDER = ./srcs/
HEADER_FOLDER = ./includes/

SRC_LIST	= \
ft_atoi.c \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_lstadd_front.c \
ft_lstnew.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

HEADER_LIST = \
libft.h

SRC = $(addprefix $(SRC_FOLDER), $(SRC_LIST))
HEADERS = $(addprefix $(HEADER_FOLDER), $(HEADER_LIST))

OTHER_DEPEND = \
Makefile

OBJS	=	$(SRC:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
AR		=	ar rcs

%.o:	%.c $(OTHER_DEPEND)
	$(CC) -c $(CFLAGS) $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
	$(AR) $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re