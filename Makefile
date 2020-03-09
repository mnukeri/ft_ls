# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 16:53:37 by mnukeri           #+#    #+#              #
#    Updated: 2019/09/12 15:20:31 by mnukeri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a
CC = gcc
FLAG = -Wall -Werror -Wextra
ARC = ar rc
SRC = ft_sorter.c ft_array_swap.c ft_content_display.c ft_dir_count.c ft_dir_copy.c ls_process.c flag_checker.c path_checker.c ft_dir_check.c ls_process_R.c ft_pr_perm.c ft_diff_flag.c ft_sorter_l.c ft_sorter_t.c ft_dir_strlen.c
OBJ = ft_sorter.o ft_array_swap.o ft_content_display.o ft_dir_count.o ft_dir_copy.o ls_process.o flag_checker.o path_checker.o ft_dir_check.o ls_process_R.o ft_pr_perm.o ft_diff_flag.o ft_sorter_l.o ft_sorter_t.o ft_dir_strlen.o

# all: ${NAME}

${NAME}:
	@echo "Creating objects.."
	@${CC} ${FLAG} -c ${SRC}
	@echo "Creating LS library.."
	@${ARC} ${NAME} ${OBJ}
	@echo "Indexing library.."
	@ranlib ${NAME}
	@echo "Compiling executable 'ft_ls'.."
	@${CC} ${FLAG} ls_main.c libft/*.o *.o -o ft_ls

all: ${NAME}

clean:
	@echo "cleaning *.o .."
	@rm -f *.o

fclean: clean
	@echo "Snapping the stones.."
	@rm -f ${NAME} ft_ls

re: fclean all
