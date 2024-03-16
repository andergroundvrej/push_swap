# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:44:50 by ahakobia          #+#    #+#              #
#    Updated: 2024/02/11 06:14:56 by ahakobia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
EXECUTABLE = ../checker
CFLAGS = -Wall -Wextra -Werror -MMD

FILES = main_bonus.c	\
		utils_bonus.c  \
		push_swap_bonus.c \
		push_and_swaps_bonus.c \
		rotate_bonus.c  \
		reverse_rotate_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		
OBJS = $(FILES:%.c=%.o)

OBJS_D = $(OBJS:%.o=%.d)

all: $(EXECUTABLE)

%.o :%.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

-include $(OBJS_D)

$(EXECUTABLE): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS_D)

fclean: clean
	$(RM) $(EXECUTABLE)

re: clean all

.PHONY: make all clean fclean re
