# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 22:26:29 by mcha              #+#    #+#              #
#    Updated: 2022/06/23 13:32:35 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX					= c++
ifdef DEBUG
	CXXFLAGS		= -std=c++98 -g
else 
	CXXFLAGS		= -std=c++98 -Wall -Wextra -Werror
endif
NAME				= zombie

RM					= rm -rf

HEAD_FILE			=	Zombie.hpp

SRCS_FILE			=	main.cpp \
						Zombie.cpp \
						zombieHorde.cpp \

OBJ					= $(SRCS_FILE:%.cpp=%.o)

%.o 				: %.cpp
					@echo "[+] Compile $<"
					@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME)				: $(OBJ) $(HEAD_FILE)
					@echo "[+] Create $(NAME) with linking"
					@$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

all					: $(NAME)

clean				: 
					@$(RM) $(OBJ)
					@echo "[-] Delete object files"

fclean				: clean
					@echo "[-] Delete run files"
					@$(RM) $(NAME)

re					:
					make fclean
					make all

debug				:
					@make DEBUG=1
					@echo "[-] DEBUG PROCESS"

.PHONY 				: all clean fclean re debug