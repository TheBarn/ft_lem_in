CC				=	gcc
NAME			=	lem-in
NAME_V			=	visu
FLAGS			=	-Wall -Wextra -Werror
FLAGS_V			=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INC_DIR			=	includes

SRCS			= 	algo/algo.c			\
					algo/prune.c		\
					algo/shortest_path.c		\
					ants/ants.c			\
					parser/parse_nb.c	\
					parser/parse_room.c	\
					parser/parse_tube.c	\
					parser/parser.c		\
					parser/parser_utils.c		\
					utils/utils.c		\
					utils/lem_utils.c	\
					main.c

SRCS_V			=	draw/main-visu.c	\
					draw/parser.c	\
					draw/parse_nb.c	\
					draw/parse_room.c	\
					draw/parse_tube.c	\
					draw/draw_lem.c	\
					draw/draw_path.c	\
					draw/draw_tubes.c	\
					draw/lem_utils.c	\
					draw/exc_paths.c	\
					draw/ants.c	\
					draw/algo.c	\
					draw/utils.c

OBJS			=	$(SRCS:.c=.o)
OBJS_V			=	$(SRCS_V:.c=.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: $(NAME) $(NAME_V)

$(NAME):	$(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

$(NAME_V):	$(LIB) $(OBJS_V)
	@$(CC) $(FLAGS_V) -o $(NAME_V) $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME_V) ] $(SUCCESS)

clean:
	@rm -f $(OBJS) $(OBJS_V)
	@make -C $(LIB_PATH) fclean
	@echo "Cleaning" [ $(NAME) $(NAME_V) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME) $(NAME_V)
	@echo "Delete" [ $(NAME) $(NAME_V) ] $(OK)

re: fclean all

.PHONY: clean all re fclean
