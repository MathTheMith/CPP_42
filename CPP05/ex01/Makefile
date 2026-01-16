NAME = Bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = src
OBJDIR = obj

SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

HEADERS = Bureaucrat.hpp Form.hpp

GREEN = \033[0;32m
GREY = \033[0;90m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "$(GREY)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@echo "$(GREY)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
