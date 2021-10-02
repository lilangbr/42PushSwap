# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebresser <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 12:56:04 by ebresser          #+#    #+#              #
#    Updated: 2020/03/09 12:15:58 by ebresser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memccpy.c ft_memchr.c \
        ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
        ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
        ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
                ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS) -c
all : $(NAME)
$(NAME): $(OBJ)
	ar rc libft.a $(OBJ)
clean:
	@/bin/rm -f $(OBJ) $(OBJ_BONUS)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
bonus: $(OBJ_BONUS) $(OBJ)
	ar rc libft.a $(OBJ) $(OBJ_BONUS)
