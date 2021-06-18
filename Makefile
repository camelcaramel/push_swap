CH_SRCS=	checker.c     \
			commands_1.c  \
			commands_2.c  \
			commands_3.c  \
			init.c        \
			quick_sort.c \
			util.c        \
			utils2.c      \
			partition.c         \
			valid_check.c 	
PS_SRCS= 	commands_1.c  \
			commands_2.c  \
			commands_3.c  \
			find_element.c\
			init.c        \
			partition.c         \
			push_swap.c   \
			quick_sort.c  \
			sorting.c     \
			static_sort.c \
			util.c        \
			utils2.c      \
			valid_check.c
SRCSDIR=./srcs
INCLUDESDIR=./includes
INCLUDES=push_swap.h
CC=gcc
FLAGS=-Wall -Wextra -Werror
CH_OBJS=$(CH_SRCS:.c=.o)
PS_OBJS=$(PS_SRCS:.c=.o)
CH_TARGET=checker
PS_TARGET=push_swap

all : $(CH_TARGET) $(PS_TARGET)

$(CH_TARGET) : $(CH_OBJS)
	$(CC) $(FLAGS) -I $(INCLUDESDIR) -o $(CH_OBJS)

$(PS_TARGET) : $(PS_OBJS)
	$(CC) $(FLAGS) -I $(INCLUDESDIR) -o $(PS_OBJS)

%($(PS_OBJS)) : $(PS_SRCS)
	$(CC) $(FLAGS) -I $(INCLUDESDIR) -c $< -o $@

clean :
	rm -rf $(PS_OBJS) $(CH_OBJS)

fclean : 
	rm -rf $(CH_TARGET) $(PS_TARGET)

re : clean all

.PHONY clean re fclean all 
