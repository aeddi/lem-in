# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 12:06:57 by aeddi             #+#    #+#              #
#    Updated: 2015/08/19 16:09:39 by aeddi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libxsimple.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I $(INCS_DIR) -I /usr/X11R6/include 
LDFLAGS			=	-L /usr/X11R6/lib -lX11 -lm
AR				=	ar
ARFLAGS			=	rc
INCS_DIR		=	./includes
OBJS_DIR		=	./objects
SRCS_DIR		=	./sources
OBJS			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
SRCS			=	xdraw.c		\
					xevent.c	\
					xinit.c		\
					xwindow.c

all				:	$(NAME)

$(NAME)			:	$(OBJS_DIR) $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "]   \033[1;32mDone\033[0;0m"

$(OBJS_DIR)/%.o	:	$(addprefix $(SRCS_DIR)/, %.c)
	@$(CC) $(CFLAGS) -o $@ -c $^
	@echo ".\c"

$(OBJS_DIR)		:
	@mkdir -p $(OBJS_DIR)
	@echo "\033[1;32mCompiling xsimple   \033[0;0m[\c"

fclean			:	clean
	@rm -f $(NAME)
	@echo "\033[1;31mCompiled xsimple deleted\033[0;0m"

clean			:
	@rm -rf $(OBJS_DIR)
	@echo "\033[1;31mObjects deleted\033[0;0m"

re				:	fclean all

.PHONY: clean all re fclean
