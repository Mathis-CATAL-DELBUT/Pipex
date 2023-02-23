# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 22:01:26 by mcatal-d          #+#    #+#              #
#    Updated: 2023/02/18 22:01:30 by mcatal-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c ft_split2.c\
					ft_strrchr.c ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c

bonus			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

gnl_SRCS		=	get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

printf_SRCS		=	ft_printf/ft_print_hex.c ft_printf/ft_print_ptr.c\
					ft_printf/ft_print_unsigned.c ft_printf/ft_printf_utils.c\
					ft_printf/ft_printf.c

OBJS			= $(SRCS:.c=.o)
OBJSbonus		= $(bonus:.c=.o)
OBJSgnl			= $(gnl_SRCS:.c=.o)
OBJSprintf		= $(printf_SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS) $(OBJSbonus) $(OBJSgnl) $(OBJSprintf)
				ar rcs $(NAME) $(OBJS) $(OBJSbonus) $(OBJSgnl) $(OBJSprintf)

bonus:			$(OBJSbonus) $(OBJS)
				ar rcs $(NAME) $(OBJSbonus) $(OBJS) 

clean:
				$(RM) $(OBJS) $(OBJSbonus) $(OBJSgnl) $(OBJSprintf)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY: all clean fclean re
