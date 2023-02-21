SRC = main.cpp vector.cpp
CFLAGS = #-Wall -Wextra -Werror -fsanitize=address
CPP = c++
NAME = ft_containers

all: $(NAME)

$(NAME): $(SRC)
	@$(CPP) $(CFLAGS) $(SRC) -o $(NAME) 

clean:

fclean : clean
	@rm -rf $(NAME)

re : fclean all

test: test_main.cpp vector.hpp iterator.hpp
	g++ test_main.cpp $(CFLAGS) -o test

.PHONY: all clean fclean re