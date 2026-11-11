NAME = morse
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC = main.c table_morse.c ft_texte_vers_morse.c ft_morse_vers_texte.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c morse.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
