# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 22:01:39 by mcatal-d          #+#    #+#              #
#    Updated: 2023/02/21 16:09:44 by mcatal-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
SRCS		= src/pipex.c src/free.c src/child.c src/utils.c src/main.c
SRCS_b		= src_bonus/pipex_bonus.c src_bonus/free_bonus.c\
				src_bonus/child_bonus.c src_bonus/utils_bonus.c\
				src_bonus/main_bonus.c
OBJS		= $(SRCS:.c=.o)
OBJS_b		= $(SRCS_b:.c=.o)
CC			= cc
RM			= rm -rf
CFLAGS		= -I./includes -I./libft -Wall -Wextra -Werror
LIBFT_DIR	= libft
LIBFT_LIB	= libft/libft.a
	
all:			$(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME):		$(OBJS) $(LIBFT_LIB) Makefile
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

bonus:			$(OBJS_b) $(LIBFT_LIB) Makefile
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS_b) $(LIBFT_LIB)

clean:
				$(RM) $(OBJS) $(OBJS_b)
				make -C $(LIBFT_DIR) clean

fclean:			clean
				$(RM) $(NAME) $(OBJS_b)
				make -C $(LIBFT_DIR) fclean

re:				fclean $(NAME)

.PHONY: all clean fclean re
