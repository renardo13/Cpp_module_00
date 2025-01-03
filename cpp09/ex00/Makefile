SRC = Srcs/main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
NAME = btc
INCLUDE = Includes
HEADERS = $(wildcard $(Includes)/*.h)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re