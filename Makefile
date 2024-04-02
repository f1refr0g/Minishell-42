CC = gcc
RM = rm -rf
NAME = minishell
FLAG = -Wall -Werror -Wextra -g
SPECIAL_FLAG = -L./readline -lreadline -lhistory
LIB_PATH = include/libft
LIBFT = ./include/libft/libft.a

SRC_DIR := srcs
FILES :=	main.c\
			env.c\
			env2.c\
			init_minishell.c\
			builtins.c\
			builtins2.c\
			builtins3.c\
			builtins4.c\
			clean.c\
			token.c\
			quote.c\
			execution.c\
			prompt.c\
			utils.c\
			strtok.c\
			set_shlvl.c\
			exec_utils.c\
			signal.c\
			
SRCS := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS_DIR := objs
OBJS := $(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

all: libinit $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(FLAG) -c $< -o $@
	@echo $(BLACKBCK)$(CYAN)[-] Compiling: $@$(ENDCOLOR)

$(NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -lncurses -o $(NAME) $(SPECIAL_FLAG) $(LIBFT)
	@echo $(SUCCESS)

libinit:
	$(MAKE) -s -C ./include/libft

COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

clean:
	$(RM) $(OBJS)
	@echo $(CLEANING)

fclean: clean
	$(RM) $(NAME) $(OBJS_DIR)
	@$(MAKE) fclean -C ./include/libft

re: fclean all

leaks: $(NAME)
	valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --show-reachable=yes --suppressions=./minishell.sup ./$(NAME)

run: $(NAME)
	@./$(NAME)

.PHONY: all clean fclean re leaks run