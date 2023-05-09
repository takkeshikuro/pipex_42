NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDES = ft_printf.h

SRC = \
	ft_printf.c \
	ft_print_adress.c \
	ft_printf_hex.c \
	ft_printstr.c \
	ft_putnbr.c 

OBJS = $(SRC:.c=.o)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :	${NAME}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS} 

fclean :	clean
	rm -f ${NAME}

re :	fclean all

.PHONY :	all clean fclean re bonus rebonus