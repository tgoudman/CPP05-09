NAME = COFFEEMAKING
CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98 -g3

SRC = AForm.cpp main.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
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
