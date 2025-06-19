NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98
DEFINES =

SRC = main.cpp PmergeMe.cpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(DEFINES) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(DEFINES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug:
	$(MAKE) re DEFINES="-DDEBUG=1"
