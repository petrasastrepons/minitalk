# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psastre <psastre@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 13:59:52 by psastre           #+#    #+#              #
#    Updated: 2024/02/10 12:51:27 by psastre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server

SRC_C = client.c
SRC_C = server.c

LIBFT = ./libft/
GNL = ./getnextline/
OBJS = ./objs

OBJS_C = $(addprefix $(OBJS)/,$(SRC_C:.c=.o))
OBJS_S = $(addprefix $(OBJS)/,$(SRC_S:.c=.o))
DEPS_C = $(addprefix $(OBJS)/,$(SRC_C:.c=.d))
DEPS_S = $(addprefix $(OBJS)/,$(SRC_S:.c=.d))

INC = -I minitalk.h\
		-I $(LIBFT)\
		-I $(GNL)

CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

-include $(DEPS_C)
-include $(DEPS_S)

all:
	$(MAKE) --no-print-directory -C $(LIBFT)
	$(MAKE) --no-print-directory -C $(GNL)
	-mkdir $(OBJS)
	$(MAKE) --no-print-directory -C $(NAME_C)
	$(MAKE) --no-print-directory -C $(NAME_S)

$(OBJS)/%.o: %.c
	$(CC) $(CFLAGS) -MMD $(INC) -c $< -o $@

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(INC) $(LIBFT)libft.a $(GNL)get_next_line.a $(OBJS_C) -o $@

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(INC) $(LIBFT)libft.a $(GNL)get_next_line.a $(OBJS_S) -o $@

clean:
	make clean --no-print-directory -C $(LIBFT)
	make clean --no-print-directory -C $(PRINTF)
	make clean --no-print-directory -C $(GNL)
	$(RM) $(NAME_C) $(NAME_S)
re: fclean all
.PHONY: all clean fclean
.SILENT:
