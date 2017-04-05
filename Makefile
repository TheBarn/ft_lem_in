CC				=	gcc -Wall -Wextra -Werror 
NAME			=	lem-in
NAME_V			=	visu

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INC_DIR			=	includes

SRCS			= 	algo/algo.c			\
					algo/prune.c		\
					algo/shortest_path.c		\
					ants/diff.c			\
					ants/move.c			\
					ants/start.c			\
					ants/step.c			\
					parser/parse_nb.c	\
					parser/parse_room.c	\
					parser/parse_pipe.c	\
					parser/parser.c		\
					parser/parser_utils.c		\
					utils/utils.c		\
					utils/lem_utils.c	\
					main.c

SRCS_V			=	algo/algo.c			\
					algo/prune.c		\
					algo/shortest_path.c		\
					ants/step.c			\
					draw/main_visu.c	\
					draw/draw_lem.c	\
					parser/parse_nb.c	\
					parser/parse_room.c	\
					parser/parse_pipe.c	\
					parser/parser.c		\
					parser/parser_utils.c		\
					utils/utils.c		\
					utils/lem_utils.c	\
					draw/draw_path.c	\
					draw/draw_pipes.c	\
					draw/exc_paths.c	\
					draw/anim.c	\
					draw/color.c	\
					draw/draw_utils.c	\
					draw/put_pipes.c	\

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
	@$(CC) -o $(NAME) $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

$(NAME_V):	$(LIB) $(OBJS_V)
	@$(CC) -o $(NAME_V) $^ $(LIB_LINK)
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
