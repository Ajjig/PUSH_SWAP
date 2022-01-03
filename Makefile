INC = push_swap.h

NAME = push_swap

CNAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	pivot.c \
		sort_five.c \
		sort.c \
		get_targets.c \
		main.c \
		args.c \
		push_swap.c
CHKR =	pivot.c \
		sort_five.c \
		sort.c \
		get_targets.c \
		checker.c \
		args.c \
		push_swap.c \
		GET_NEXT_LINE/get_next_line.c \
		GET_NEXT_LINE/get_next_line_utils.c

SRC_O = ${SRC:.c=.o}

CHKR_O = ${CHKR:.c=.o}

all : $(NAME) $(CNAME) $(INC)

$(NAME): $(SRC_O)

$(CNAME): $(CHKR_O)

clean:
	-@rm -rf $(CHKR_O) $(SRC_O)

fclean: clean
	-@rm -rf $(CNAME) $(NAME)

re: clean all

test:
	bash test_bash/test.sh

.PHONY = clean fclean all re test
