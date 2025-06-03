NAME = scalarConverter
CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98

SRC = main.cpp ScalarConverter.cpp ConvertFromChar.cpp ConvertFromFloat.cpp ConvertFromDouble.cpp ConvertFromInt.cpp \
other.cpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
