CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = .obj
NAME = MutantStack
SRCS_LIST = main.cpp 
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_LIST:.cpp=.o))
HEADERS_LIST = MutantStack.hpp
HEADERS_DIR = inc
HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_LIST))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g3 $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) -g3 $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
