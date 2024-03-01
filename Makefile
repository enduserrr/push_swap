NAME		= push_swap
SRC_DIR		= src
OBJ_DIR		= obj
SUB_DIR		= sort utils
BONUS		= checker
BONUS_SRC	= bonus
BONUS_OBJ	= obj_bonus

SRCS		= $(addprefix $(SRC_DIR)/sort/, p.c rr.c r.c s.c sort.c sort_three.c) \
				$(addprefix $(SRC_DIR)/utils/, split.c stack_utils.c error_free.c \
				init_nodes.c init_stack.c) \
				$(addprefix $(SRC_DIR)/, main.c)
OBJ			= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
INC			= -I incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)
			@$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re