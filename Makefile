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

all : echo-ps $(NAME)

bonus: $(CNAME)

$(NAME): $(SRC_O) $(INC)
	$(CC) $(SRC_O) -o $(NAME)

$(CNAME): $(CHKR_O) $(INC)
	$(CC) $(CHKR_O) -o $(CNAME)

clean:
	-@rm -rf $(CHKR_O) $(SRC_O)

fclean: clean
	-@rm -rf $(CNAME) $(NAME)

re: clean all

test:
	bash test_bash/test.sh

echo-ps:
	@echo "\x1B[36m ██▓███   █    ██   ██████  ██░ ██   ██████  █     █░ ▄▄▄       ██▓███"
	@echo "▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒"
	@echo "▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒"
	@echo "▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░▓█ ░██   ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒"
	@echo "▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░"
	@echo "▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░"
	@echo "░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░     "
	@echo "░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░░  ░  ░    ░   ░    ░   ▒   ░░       "
	@echo "            ░           ░   ░  ░  ░      ░      ░          ░  ░         "

.PHONY = clean fclean all re test
