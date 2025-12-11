NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

AR := ar
AFLAGS := rcs

HEADER := libft.h


SRCS_LIB := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_isspace.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c

SRCS_LIB_DIR := srcs/libft/

SRCS_PRINTF := ft_printf.c ft_putnbr.c

SRCS_PRINTF_DIR := srcs/ft_printf/

# SRCS_GNL := get_next_line.c

# SRCS_GNL_DIR := srcs/get_next_line/


# SRCS_DIR := srcs/
SRCS := $(addprefix $(SRCS_LIB_DIR), $(SRCS_LIB))\
		$(addprefix $(SRCS_PRINTF_DIR), $(SRCS_PRINTF))\
# 		$(addprefix $(SRCS_GNL_DIR), $(SRCS_GNL))

OBJS_DIR := objs/
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))



.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(AR) $(AFLAGS) -o $@ $(OBJS)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)$(SRCS_LIB_DIR)
	mkdir -p $(OBJS_DIR)$(SRCS_PRINTF_DIR)
# 	mkdir -p $(OBJS_DIR)$(SRCS_GNL_DIR)

$(OBJS_DIR)%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $^ -o $@

clean :
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
