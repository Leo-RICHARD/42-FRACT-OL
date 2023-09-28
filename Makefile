# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:05:39 by lrichard          #+#    #+#              #
#    Updated: 2021/11/26 00:18:34 by lrichard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCSDIR			= sources

SRCS			= main.c launch.c controls_keyboard.c controls_mouse.c \
				  drawfract.c buddhabrot.c screenshot.c

OBJS			= $(addprefix $(SRCSDIR)/, $(SRCS:.c=.o))

HEADERSDIR		= includes

HEADERS			= $(HEADERSDIR)/fractol.h

$(SRCSDIR)/%.o: $(SRCSDIR)/%.c $(HEADERS)
				$(CC) $(CFLAGS) -I $(HEADERSDIR) -I $(LIBFTDIR) -I $(MLXDIR) -c $< -o $@

LIBFTDIR		= LIBFT

LIBFTA			= $(LIBFTDIR)/libft.a

MLXDIR			= MLX

MLXA			= $(MLXDIR)/libmlx.a

NAME			= fractol

CFLAGS			= -Wall -Wextra -Werror -I MLX -O3 -march=native

CC				= gcc

RM				= rm -f

all:			mklibfta $(NAME)

mklibfta:
				$(MAKE) -C ./LIBFT

$(NAME):		$(OBJS) $(LIBFTA) $(MLXA) $(HEADERS)
				$(CC) $(CFLAGS) -I $(HEADERSDIR) -I $(LIBFTDIR) -I $(MLXDIR) \
					$(OBJS) $(LIBFTA) $(MLXA) -L MLX -l MLX -framework OpenGL -framework AppKit -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			mklibfta all clean fclean re
