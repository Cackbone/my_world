#------------------------------------#
#         The Makefile V1            #
#        by Cedric Legendre          #
#                                    #
#------------------------------------#

ifeq (/bin/zsh, $(wildcard /bin/zsh))
SHELL		:=	/bin/zsh
endif

CC		=	gcc
NAME		=	my_world
CFLAGS		=	-W -Werror -Wextra -Wall
CINCS		=	-Iinclude -g
LIBS		=	-lm -lc_graph_prog
NB_THREAD	=	-DNB_THREAD=$(shell nproc)

BASIC_FN	=	list/list\
			list/modifiers\
			my_free_array\
			my_concat\
			my_getnbr\
			my_puterr\
			my_put_nbr\
			my_utils\
			my_strcmp\
			my_strsplit\
			my_str_isnum\
			my_strdup\
			my_strncmp\
			my_strcat\
			my_memset

ACTIONS	=	my_load\
			my_pause\
			my_reset\
			my_save\
			my_quit\
			my_texture

FILES		=	ui\
			env\
			map\
			main\
			game\
			utils\
			window\
			player\
			events\
			parser\
			button\
			textbox\
			events2\
			events3\
			hashmap\
			vectors\
			my_paint\
			selector\
			renderer\
			shellsort\
			destroyer\
			transform\
			map_saver\
			map_render\
			button_utils\
			hashmap_func\
			rotate_texture\
			map_projection\
			textbox_modifier\
			$(addprefix actions/, $(ACTIONS))\
			$(addprefix basic_fn/, $(BASIC_FN))

ifeq ($(MAKECMDGOALS),leaks)
CFLAGS		+=	-g3
else
CFLAGS		+=	-g0
endif

SRC		=	$(addsuffix .c, $(FILES))
SRC_PATH	=	$(addprefix src/, $(SRC))
OBJ		=	$(SRC_PATH:src/%.c=obj/%.o)

T_RESET	=	\033[0m
T_TITLE	=	$(T_RESET)\033[1;36m
T_DELETE	=	$(T_RESET)\033[1;31m
T_FILE		=	$(T_RESET)\033[1;33m
T_TEST		=	$(T_RESET)\033[1;33m

all: dirobj $(NAME)

$(NAME): $(OBJ)
	@echo -e "\n$(T_TITLE)Compiling binary:$(T_FILE)\t$(shell pwd)/$(NAME)$(T_RESET)\n"
	$(CC) $(NB_THREAD) $(OBJ) -o $(NAME) $(LIBS)
	@echo -e "\n$(T_TITLE)$(NAME)\t\t\t$(T_FILE)Created$(T_RESET)\n"

obj/%.o : src/%.c
	$(CC) $(CFLAGS) $(CINCS) -o $@ -c $^

clean:
	test ! -d obj ||\
		echo -e "$(T_DELETE)Delete:$(T_FILE)\t\t\t$(shell pwd)/obj$(T_RESET)" && \
		rm -rf obj

oclean:
	test ! -d outputs || \
		echo -e "$(T_DELETE)Delete:$(T_FILE)\t\t\t$(shell pwd)/outputs$(T_RESET)" && \
		rm -rf outputs

fclean: clean oclean
	test ! -f $(NAME) || \
		echo -e "$(T_DELETE)Delete:$(T_FILE)\t\t\t$(shell pwd)/$(NAME)$(T_RESET)" && \
		rm -f $(NAME)

re: fclean all

dirobj:
	test -d obj || \
		echo -e "$(T_TITLE)Create:$(T_FILE)\t\t\t$(shell pwd)/obj$(T_RESET)" && \
		mkdir -p obj
		mkdir -p obj/basic_fn
		mkdir -p obj/basic_fn/list
		mkdir -p obj/actions

leaks: re
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)
