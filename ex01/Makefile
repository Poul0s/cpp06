CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp			\
			Data.cpp			\
			Serializer.cpp		\

OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

OBJ_DIR	=	$(sort $(dir $(OBJ)))

HEADER	=	-I.

NAME	=	serializer

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) $(HEADER) $^ -o $@ -c

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re
