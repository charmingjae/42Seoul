# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 19:20:43 by mcha              #+#    #+#              #
#    Updated: 2022/02/03 00:39:29 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Default
CC			= gcc
RM			= rm -rf
CFLAGS		= -I $(HEADER_ROOT) -Wall -Werror -Wextra
LIBFLAGS	= -lmlx -framework OpenGL -framework AppKit

# Name
NAME		= so_long

# Dependencies
LIBFT		= ./srcs/libft/libft.a

# Path
HEADER_ROOT	= includes
OBJS_ROOT	= objs
SRCS_ROOT	= srcs
LIBX_ROOT	= minilibx
LIBFT_ROOT	= ./srcs/libft

# Binding
vpath %.c $(SRCS_ROOT)
OBJS := main.o get_next_line.o map.o map_util_one.o map_util_two.o \
		comm_util.o game.o key_detect.o
OBJS := $(addprefix $(OBJS_ROOT)/, $(OBJS))

# Commands
all : $(NAME)

$(OBJS_ROOT)/%.o : %.c
	@echo "[+] Linking $<"
	@$(CC) $(CFLAGS) -c -o $@ $<


$(NAME) : $(OBJS)
	@make -s -C $(LIBX_ROOT)
	@make -s -C $(LIBFT_ROOT)
	@$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ $(OBJS) $(LIBFT) -L $(LIBX_ROOT)
	@echo "[+] Create so_long"

clean :
	@make clean -C $(LIBX_ROOT)
	@$(RM) $(OBJS)

fclean : clean
	@make fclean -C $(LIBFT_ROOT)
	@$(RM) $(NAME)
	@echo "[-] Delete run files"

re : fclean all

.PHONY : all clean fclean re