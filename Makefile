NAME = push_swap

CC = clang

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

HEADERS = -I ./includes

LIBFT_DIR = ./libft

ADD_LIBS = -L $(LIBFT_DIR) -lft

SRCS = ./src/checkers.c \
	./src/main.c \
	./src/order_more_than_five.c \
	./src/order_two.c \
	./src/stack_basic_operations.c \
	./src/which_algorithm.c \
	./src/finders.c \
	./src/move.c \
	./src/order_three.c \
	./src/staff.c \
	./src/initializer.c \
	./src/normalize.c \
	./src/order_three_plus.c \
	./src/push_swap_operations.c \
	./src/validate_args.c \

OBJS = $(SRCS:.c=.o)

RM = /bin/rm -f

all:	$(NAME)

$(NAME):	$(OBJS) dep_libft
	$(CC) $(FLAGS) $(HEADERS) $(OBJS) $(ADD_LIBS) -o $@ 

%.o:	%.c    
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

dep_libft:
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) ./src/*.o

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	
re: fclean all

.PONY: all clean fclean re
