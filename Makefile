SRC = *.cpp

# FLAGS = -Wall -Wextra - Werror


NAME = -o a.out

all:
	g++ $(NAME) $(SRC) -I ./
fclean:
	rm a.out
	
# g++ $(FLAGS) $(NAME) $(SRC) -I ./