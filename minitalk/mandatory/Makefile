# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 19:08:29 by mcha              #+#    #+#              #
#    Updated: 2022/01/21 21:14:57 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
RM 			= rm -rf
CFLAGS		= -I $(HEADER_ROOT) -Wall -Werror -Wextra

SERVER_NAME	= server
CLIENT_NAME	= client
NAME		= $(SERVER_NAME) $(CLIENT_NAME)

HEADER_ROOT = includes
OBJS_ROOT	= objs
SRCS_ROOT	= srcs
CLIENT_ROOT	= $(join $(SRCS_ROOT)/, client)
SERVER_ROOT	= $(join $(SRCS_ROOT)/, server)

FT_PRINTF	= ./srcs/ft_printf/libftprintf.a

vpath %.c $(CLIENT_ROOT) $(SERVER_ROOT)

SERVER_OBJS := server.o handle.o
SERVER_OBJS	:= $(addprefix $(OBJS_ROOT)/, $(SERVER_OBJS))
CLIENT_OBJS := post.o client.o
CLIENT_OBJS	:= $(addprefix $(OBJS_ROOT)/, $(CLIENT_OBJS))

all : $(NAME)

$(OBJS_ROOT)/%.o : %.c
	@echo "[~] Linking $<"
	@$(CC) $(CFLAGS) -c -o $@ $<
			
$(SERVER_NAME) : $(SERVER_OBJS) $(FT_PRINTF)
			@echo "[+] Create server"
			@$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(FT_PRINTF)
			
$(CLIENT_NAME) : $(CLIENT_OBJS) $(FT_PRINTF)
			@echo "[+] Create client"
			@$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(FT_PRINTF)

clean :
		@$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
		@echo "[-] Delete object files"

fclean : clean
		@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
		@echo "[-] Delete run files"

re : fclean all

.PHONY : all clean fclean re