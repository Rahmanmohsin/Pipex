CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRCS =  pipex.c pipex_utils.c pipex_utils_2.c pipex_utils_3.c

OBJS = $(SRCS:.c=.o)

LIB = Libft.a
LIBRARY_DIR = Libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBRARY_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBRARY_DIR) -lft

clean:
	rm -f $(OBJS)
	make -C $(LIBRARY_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBRARY_DIR) fclean

re: fclean all