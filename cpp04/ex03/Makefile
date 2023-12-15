NAME = ex03
CXX = c++ -std=c++98 -Wall -Wextra -Werror -g
SRCS = AMateria.cpp Cure.cpp Ice.cpp \
		Character.cpp MateriaSource.cpp \
		main.cpp Floor.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re