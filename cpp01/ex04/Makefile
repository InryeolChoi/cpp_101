NAME = file_transform
CXX = c++ -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp FileChange.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS)
	rm -rf *.replace

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re