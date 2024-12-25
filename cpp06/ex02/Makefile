SRC = Srcs/main.cpp Srcs/A.cpp Srcs/B.cpp Srcs/C.cpp Srcs/Base.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = Base
INCLUDE = Includes
HEADERS = $(wildcard $(INCLUDE)/*.h)

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