.PHONY: all clean fclean re

NAME 	:=	libft.a

CC		:=	gcc

CFLAGS	:= -g3 -Wextra -Werror -Wall

SRC		:=	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \
			ft_substr.c \
			ft_abs.c \
			ft_abs_float.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strjoin.c \
			ft_calloc.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strmapi.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_memcmp.c \
			ft_memccpy.c \
			ft_split.c \
			ft_strtrim.c \
			ft_isnegative.c \
			ft_itoa.c \
			ft_isspace.c \
			ft_max.c \
			ft_min.c \
			ft_memdel.c \
			ft_strrev.c \
			get_next_line.c \
			ft_ptoa.c \
			to_string.c \
			ft_ctoa.c \
			ft_utoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c

SRC_FOLDER 	:= src

OBJ_FOLDER	:= obj

SRCS 		:= $(addprefix ${SRC_FOLDER}/, ${SRC})

OBJS 		:= $(addprefix ${OBJ_FOLDER}/, ${SRCS:.c=.o})

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME)	: $(OBJS)
	ar crs $(NAME) $(OBJS)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -rf $(NAME)

re: fclean ${NAME}
