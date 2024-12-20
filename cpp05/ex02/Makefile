SRC = Srcs/main.cpp Srcs/Bureaucrat.cpp \
Srcs/AForm.cpp Srcs/ShrubberyCreationForm.cpp \
Srcs/RobotomyRequestForm.cpp Srcs/PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
NAME = 28B
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