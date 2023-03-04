# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 15:56:52 by mcha              #+#    #+#              #
#    Updated: 2022/06/20 20:40:03 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX					= c++
CXXFLAGS			= -std=c++98 -Wall -Werror -Wextra
NAME				= phonebook

RM					= rm -rf

HEAD_FILE			=	PhoneBook.hpp \
						Contact.hpp \
						Controller.hpp \
						InputView.hpp \
						OutputView.hpp \

SRCS_FILE			=	main.cpp \
						PhoneBook.cpp \
						Contact.cpp \
						Controller.cpp \
						InputView.cpp \
						OutputView.cpp \

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