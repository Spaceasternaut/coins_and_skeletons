SRCS	=  ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memcmp.c \
ft_memchr.c \
ft_strlen.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strchr.c \
ft_strlcpy.c \
ft_atoi.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_tolower.c \
ft_toupper.c \
ft_strncmp.c \
ft_calloc.c \
ft_strdup.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_strjoin.c \
ft_strlcat.c \
ft_itoa.c \
ft_substr.c \
ft_strtrim.c \
ft_split.c

HDR		= libft.h

OBJS	= $(patsubst %.c, %.o,$(SRCS))

NAME 	= libft.a

GCC		= gcc
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o :		%.c ${HDR}
			@${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@echo "Making the library..."
			@ar rc ${NAME} $?
			@ranlib ${NAME}
			@echo "Library is complete.\n"

clean:		
			@echo "Cleaning the library..."
			@${RM} ${OBJS}
			@echo "Cleaned the library folder.\n"

fclean:		clean
			@echo "Removing library..."
			@${RM} ${NAME}
			@echo "Library removed successfully.\n"

re:			fclean all