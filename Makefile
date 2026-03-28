NAME = minitalk
SNAME = server
CNAME = client
LIBFT = libft.a
CC = cc
all: CFLAGS = -Wall -Wextra -Werror
all: DMODE =
debug: CFLAGS = -Wall -Wextra -Werror -g
debug: DMODE = (debug mode)\n
BUFF_SIZE = -D BUFFER_SIZE=1
NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m

SSRCS = server.c
SOBJS = $(SSRCS:.c=.o)

CSRCS = client.c
COBJS = $(CSRCS:.c=.o)

OBJS = $(SOBJS) $(COBJS)

all: $(NAME)

debug: $(NAME)

re: fclean all

$(NAME): $(LIBFT) $(SNAME) $(CNAME)

$(CNAME): $(COBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${YELLOW}Building ${BLUE}$@ ${YELLOW}${DMODE}\n${NEUTRAL}"

$(SNAME): $(SOBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${YELLOW}Building ${BLUE}$@ ${YELLOW}${DMODE}\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) $(BUFF_SIZE) -o $@ -c $^
	@printf "Compiling ${BLUE}$^ ${YELLOW}${DMODE}\n${NEUTRAL}"

$(LIBFT):
	@make -C libft
	@mv ./libft/libft.a ./
	@make -C libft fclean

fclean: clean
	@rm -f $(SNAME) $(CNAME) $(LIBFT)
	@printf "${RED}Deleting archives and binaries\n${NEUTRAL}"

clean:
	@rm -f $(OBJS)
	@printf "${RED}Deleting object files\n${NEUTRAL}"

.PHONY: all fclean clean re
