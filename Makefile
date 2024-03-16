# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:44:50 by ahakobia          #+#    #+#              #
#    Updated: 2024/03/09 18:25:59 by ahakobia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
EXECUTABLE = push_swap
CFLAGS = -Wall -Wextra -Werror -MMD

FILES = srcs/main.c	\
		srcs/utils.c  \
		srcs/push_swap.c \
		srcs/push_and_swaps.c \
		srcs/rotate.c  \
		srcs/reverse_rotate.c \
		srcs/find_nbr.c \
		srcs/rank.c \
		srcs/sorting_stack.c \
		

OBJS = $(FILES:%.c=%.o)

OBJS_D = $(OBJS:%.o=%.d)

all: $(EXECUTABLE)

%.o :%.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

-include $(OBJS_D)

$(EXECUTABLE): $(OBJS) srcs/push_swap.h push_swap_bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS_D) 

fclean: clean
	$(RM) $(EXECUTABLE)
	$(RM) checker
	$(RM) ./push_swap_bonus/*.o
	$(RM) ./push_swap_bonus/*.d
	$(RM) push_swap.d

re: clean all

bonus: 
	$(MAKE) -C ./push_swap_bonus
		
.PHONY: make all clean fclean re bonus
