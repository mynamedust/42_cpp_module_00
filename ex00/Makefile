NAME		=	megaphone
SRCS		=	$(wildcard ./*.cpp)
OBJS_DIR	=	./obj
OBJS		=	$(SRCS:./%.cpp=$(OBJS_DIR)/%.o)
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(OBJS_DIR)/%.o: ./%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re