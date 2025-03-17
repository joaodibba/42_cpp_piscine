NAME = Intern
CXX = c++
CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror
SRC =	src/main.cpp \
		src/AForm.cpp \
		src/Bureaucrat.cpp \
		src/PresidentialPardonForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/ShrubberyCreationForm.cpp \
		src/Intern.cpp

OBJ = $(SRC:src/%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^

obj/%.o: src/%.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re