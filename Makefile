# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 10:19:53 by aarranz-          #+#    #+#              #
#    Updated: 2023/10/17 12:12:37 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CC = cc
FLAGS = -Wall -Wextra -Werror

all:

	@$(CC) $(FLAGS) client.c  -o $(CLIENT)

	@$(CC) $(FLAGS) server.c  -o $(SERVER)

%.o:%.c 
	@$(CC) $(FLAGS)

clean:
	@rm -f $(CLIENT) $(SERVER)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	
re: fclean all