NAME = ex02
CXX = c++ -std=c++98 -Wall -Wextra -Werror -g
SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp
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