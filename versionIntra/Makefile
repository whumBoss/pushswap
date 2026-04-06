# ===== Target =====
NAME = push_swap

# ===== Directories =====
PRINTF_DIR = includes/ft_printf/
OBJ_DIR = objs

# ===== Libraries =====
PRINTF = $(PRINTF_DIR)libftprintf.a

# ===== Toolchain =====
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -I. -Includes -Includes/ft_print -MMD -MP

# ===== Source Layout =====
MAIN_DIR = src/
PARSING_DIR = src/parsing/
SORTING_DIR = src/sorting/
ALGO_DIR = src/algo/
UTILS_DIR = src/utils/

MAIN_FILES = main.c
PARSING_FILES = check.c fill.c
SORTING_FILES = mouv_sp.c mouv_rrr.c
ALGO_FILES = small_algo.c big_algo.c
UTILS_FILES = ft_atoi.c ft_split.c list.c free.c

# ===== Source / Object / Dependency Lists =====
SRCS = \
	$(addprefix $(MAIN_DIR),$(MAIN_FILES)) \
	$(addprefix $(PARSING_DIR),$(PARSING_FILES)) \
	$(addprefix $(SORTING_DIR),$(SORTING_FILES)) \
	$(addprefix $(ALGO_DIR),$(ALGO_FILES)) \
	$(addprefix $(UTILS_DIR),$(UTILS_FILES)) \

OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

# ===== Build Rules =====
all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ===== Cleanup =====
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

# ===== Test Helpers =====
test: $(NAME)
	./$(NAME) 1 13 54 34

signtest: $(NAME)
	./$(NAME) 34 -54 +12 -1

wrongsign: $(NAME)
	./$(NAME) 12 ++32 - 45

# ===== Auto Dependencies =====
-include $(DEPS)

.PHONY: all clean fclean re test hardtest noinfile