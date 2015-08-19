# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 16:00:35 by aeddi             #+#    #+#              #
#    Updated: 2015/08/19 16:10:55 by aeddi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in
NAME2			=	visu-hex

CC				=	gcc
GDB				?=	0
ifeq ($(GDB), 1)
	CFLAGS		=	-Wall -Wextra -Werror -g3 -I $(LIBFT_DIR)/includes -I $(LIBXS_DIR)/includes -I /usr/X11R6/include -I $(INCS_DIR)
else
	CFLAGS		=	-Wall -Wextra -Werror -I $(LIBFT_DIR)/includes -I $(LIBXS_DIR)/includes -I /usr/X11R6/include -I $(INCS_DIR)
endif

LFLAGS			=	-L $(LIBFT_DIR) -lft -L $(LIBXS_DIR) -lxsimple -L /usr/X11R6/lib -lX11 -lm
LIBFT_DIR		=	./libft
LIBXS_DIR		=	./libxsimple

INCS_DIR		=	./includes
OBJS_DIR		=	./objects

SRCS_LEM_DIR	=	./sources/lem-in
SRCS_LEM		=	main.c						\
					calc_process.c				\
					free_struct.c				\
					malloc_struct.c				\
					parse_entry.c				\
					read_line.c					\
					ft_tabdel.c					\
					display.c
OBJS_LEM_DIR	=	$(OBJS_DIR)/lem-in
OBJS_LEM		=	$(patsubst %.c, $(OBJS_LEM_DIR)/%.o, $(SRCS_LEM))

SRCS_VIS_DIR	=	./sources/visu-hex
SRCS_VIS		=	example.c
OBJS_VIS_DIR	=	$(OBJS_DIR)/visu-hex
OBJS_VIS		=	$(patsubst %.c, $(OBJS_VIS_DIR)/%.o, $(SRCS_VIS))

all				:	$(NAME) $(NAME2)

$(NAME)			:	$(OBJS_DIR) $(OBJS_LEM)
	$(CC) -o $(NAME) $(OBJS_LEM) $(LFLAGS)

$(NAME2)		:	$(OBJS_DIR) $(OBJS_VIS)
	$(CC) -o $(NAME2) $(OBJS_VIS) $(LFLAGS)

$(OBJS_LEM_DIR)/%.o	:	$(addprefix $(SRCS_LEM_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_VIS_DIR)/%.o	:	$(addprefix $(SRCS_VIS_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_DIR)		:	make_libs
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_LEM_DIR)
	@mkdir -p $(OBJS_VIS_DIR)

make_libs		:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(LIBXS_DIR)

fclean			:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
