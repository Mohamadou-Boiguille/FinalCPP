CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = .obj
NAME = PmergeMe

SRCS_LIST = $(wildcard $(SRCS_DIR)/*.cpp)
OBJS_LIST = $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS_LIST))
HEADERS_LIST = $(wildcard inc/*.hpp)

all: $(NAME)

$(NAME): $(OBJS_LIST)
	$(CC) -g3 $(CFLAGS) -Iinc $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS_LIST) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) -g3 $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
