CC				=	gcc
NAME			=	lem_in
CFLAGS			+=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INC_DIR			=	includes

SRCS			= 	algo/algo.c			\
					algo/order.c		\
					ants/ants.c			\
					draw/draw_lem.c		\
					draw/draw_tubes.c	\
					parser/parse_nb.c	\
					parser/parse_room.c	\
					parser/parse_tube.c	\
					parser/parser.c		\
					utils/utils.c		\
					main.c

OBJS			=	$(SRCS:.c=.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME):	$(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) fclean
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean
