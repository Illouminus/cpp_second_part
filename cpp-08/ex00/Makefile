NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJDIR = obj

SRCS = main.cpp 


OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

INCLUDES = includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJDIR)/src/%.o: src/%.cpp | $(OBJDIR)/src
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJDIR)/main.o: main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJDIR)/src:
	mkdir -p $(OBJDIR)/src

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
