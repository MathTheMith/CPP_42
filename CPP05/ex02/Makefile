# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvachon <mvachon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 12:48:15 by mvachon           #+#    #+#              #
#    Updated: 2025/12/03 12:48:15 by mvachon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

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
