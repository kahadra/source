# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunpark <seunpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 22:18:03 by seunpark          #+#    #+#              #
#    Updated: 2022/02/07 15:56:31 by seunpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

UTIL_DIR	=	utils/
SORT_DIR	=	sorts/
PRE_DIR		=	preprocess/
STACK_DIR	=	stack/
RE_DIR		=	re/

SRC_DIR		=	./src/
MAIN_FILE	=	main.c
PRE_FILE	=	$(addprefix $(PRE_DIR), preprocess.c)
RE_FILE		=	$(addprefix $(RE_DIR), re_a.c) \
				$(addprefix $(RE_DIR), re_b.c)
SORT_FILE	=	$(addprefix $(SORT_DIR), sort_four_only.c) \
				$(addprefix $(SORT_DIR), sort_four.c) \
				$(addprefix $(SORT_DIR), sort_three_a.c) \
				$(addprefix $(SORT_DIR), sort_three_b.c) \
				$(addprefix $(SORT_DIR), sort_three_only.c)
STACK_FILE	=	$(addprefix $(STACK_DIR), stack_operate_1.c) \
				$(addprefix $(STACK_DIR), stack_operate_2.c) \
				$(addprefix $(STACK_DIR), stack_operate_3.c)
UTIL_FILE	=	$(addprefix $(UTIL_DIR), util_list_1.c) \
				$(addprefix $(UTIL_DIR), util_list_2.c) \
				$(addprefix $(UTIL_DIR), util_preprocess.c) \
				$(addprefix $(UTIL_DIR), util_sort.c) \
				$(addprefix $(UTIL_DIR), util_stack_1.c) \
				$(addprefix $(UTIL_DIR), util_stack_2.c) \
				$(addprefix $(UTIL_DIR), util_std.c)
SOURCES		=	$(addprefix $(SRC_DIR), $(MAIN_FILE)) \
				$(addprefix $(SRC_DIR), $(UTIL_FILE)) \
				$(addprefix $(SRC_DIR), $(SORT_FILE)) \
				$(addprefix $(SRC_DIR), $(PRE_FILE)) \
				$(addprefix $(SRC_DIR), $(STACK_FILE)) \
				$(addprefix $(SRC_DIR), $(RE_FILE))

OBJ_DIR		=	./obj/
OBJ_FILE	=	$(MAIN_FILE:.c=.o) \
				$(UTIL_FILE:.c=.o) \
				$(SORT_FILE:.c=.o) \
				$(PRE_FILE:.c=.o) \
				$(STACK_FILE:.c=.o) \
				$(RE_FILE:.c=.o)
OBJECTS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))

INCDIR		=	./includes/

RM			=	rm -rf

MKDIR		=	$(shell mkdir $(OBJ_DIR) 2> /dev/null) \
				$(shell mkdir $(OBJ_DIR)$(UTIL_DIR) 2> /dev/null) \
				$(shell mkdir $(OBJ_DIR)$(SORT_DIR) 2> /dev/null) \
				$(shell mkdir $(OBJ_DIR)$(PRE_DIR) 2> /dev/null) \
				$(shell mkdir $(OBJ_DIR)$(STACK_DIR) 2> /dev/null) \
				$(shell mkdir $(OBJ_DIR)$(RE_DIR) 2> /dev/null)

all				:	$(MKDIR) $(NAME)

*/%.o	: */%.c
	$(CC) $(CCFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME) 		: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -I$(INCDIR) -o $(NAME)

clean			:
	$(RM) $(OBJ_DIR)

fclean			: clean
	$(RM) $(NAME)

re				: fclean
	make all

.PHONY: all clean fclean re
