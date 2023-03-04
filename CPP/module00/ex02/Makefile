# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 22:26:29 by mcha              #+#    #+#              #
#    Updated: 2022/06/22 13:41:47 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX					= c++
CXXFLAGS			= -std=c++98 -Wall -Werror -Wextra
NAME				= bank

RM					= rm -rf

HEAD_FILE			=	Account.hpp

SRCS_FILE			=	Account.cpp \
						test.cpp \

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

.PHONY 				: all clean fclean re