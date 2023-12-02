NAME = fixed_point
CXX = c++ -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp
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