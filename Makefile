NAME = micro_paint

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -f

SRC = micro_paint.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all