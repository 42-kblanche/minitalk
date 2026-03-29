NAME = libft.a
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror
NEUTRAL = \033[0;0m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m

SRCS = ft_calloc.c \
	   ft_atoi.c \
	   ft_atol.c \
	   ft_isspace.c \
	   ft_isdigit.c \
	   ft_itoa.c \
	   ft_itoh.c \
	   ft_memcpy.c \
	   ft_ptoh.c \
	   ft_putstr_fd.c \
	   ft_strdup.c \
	   ft_strfind.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   buffft/ft_buff_append.c \
	   buffft/ft_buff_assign.c \
	   buffft/ft_buff_destroy.c \
	   buffft/ft_buff_double_size.c \
	   buffft/ft_buff_erase.c \
	   buffft/ft_buff_init.c \
	   buffft/ft_buff_insert.c \
	   buffft/ft_buff_insert_2.c \
	   buffft/ft_buff_print.c \
	   buffft/ft_buff_substr.c \
	   printfft/ft_printf_parse.c \
	   printfft/ft_printf_parse_2.c \
	   printfft/ft_errorf.c \
	   printfft/ft_putf.c \
	   printfft/ft_printf.c \
	   printfft/ft_printf_va.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@printf "${YELLOW}Building library ${BLUE}${NAME}\n${NEUTRAL}"

%.o: %.c
	@$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $^

fclean: clean
	@rm -f $(NAME) $(TEST_O)
	@printf "${RED}Deleting libft archive\n${NEUTRAL}"

clean:
	@rm -f $(OBJS)
	@printf "${RED}Deleting libft object files\n${NEUTRAL}"

.PHONY: ftest test all fclean clean re
