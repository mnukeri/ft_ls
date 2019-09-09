# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 16:53:37 by mnukeri           #+#    #+#              #
#    Updated: 2019/09/09 17:46:10 by mnukeri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a
CC = gcc
FLAG = -Wall -Werror -Wextra
ARC = ar rc
SRC = ft_sorter.c ft_array_swap.c ft_content_display.c ft_dir_count.c ft_dir_copy.c ls_process.c flag_checker.c
OBJ = ft_sorter.o ft_array_swap.o ft_content_display.o ft_dir_count.o ft_dir_copy.o ls_process.o flag_checker.o

# all: ${NAME}

${NAME}:
	@echo "Creating objects.."
	@${CC} ${FLAG} -c ${SRC}
	@echo "Creating LS library.."
	@${ARC} ${NAME} ${OBJ}
	@echo "Indexing library.."
	@ranlib ${NAME}
	@echo "Compiling executable 'ft_ls'.."
	@${CC} ${FLAG} ls_main.c libft/libft.a ft_ls.a -o ft_ls

all: ${NAME}

clean:
	@echo "cleaning *.o .."
	@rm -f *.o

fclean: clean
	@echo "Snapping the stones.."
	@rm -f ${NAME} ft_ls

re: fclean all
