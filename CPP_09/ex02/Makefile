NAME = PmergeMe
CXX = c++
CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror
SRC = 	src/main.cpp
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

re: fclean all

.PHONY: all clean fclean re