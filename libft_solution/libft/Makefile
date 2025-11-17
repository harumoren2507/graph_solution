# Basic Configuration
NAME=libft.a

CC=cc
CFLAGS=-Wall -Wextra -Werror

# Source files and object files
SRCS=ft_isprint.c ft_isalnum.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_fprintf.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_itoa.c get_next_line.c get_next_line_utils.c

SRCS_BONUS= ft_lstnew.c ft_lstiter.c ft_lstclear.c \
ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c \
ft_lstsize.c ft_lstadd_front.c ft_lstmap.c \

PRINTF_SRCS = ft_printf/ft_itoa_base.c ft_printf/ft_itoa_base_ptr.c \
              ft_printf/ft_print_address.c ft_printf/ft_print_csdi_fmt.c \
              ft_printf/ft_printf.c ft_printf/ft_print_hex.c \
              ft_printf/ft_print_percent.c

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
INCLUDES = -I. -I./ft_printf/

OBJS=$(SRCS:.c=.o)
ifdef WITH_BONUS
OBJS+=$(SRCS_BONUS:.c=.o)
endif

OBJS_BONUS=$(SRCS_BONUS:.c=.o)

# Build target
all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_OBJS)
	ar rc $(NAME) $(OBJS) $(PRINTF_OBJS)
	ranlib $(NAME)

bonus:
	make WITH_BONUS=1 all

# Compile rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup targets
clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
