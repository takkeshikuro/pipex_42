NAME    = pipex
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -I ./include/pipex.h

LIBFT  	= ./libs/libft/
PRINTF  = ./libs/printf/
PRINTF_DIR = libs/printf/libftprintf.a

SRCS 	= $(wildcard *.c)

LIBFLAGS = -g

OBJS 	=  $(SRCS:.c=.o)

NC		:= \033[m
B_RED	:= \033[1;31m
RED 	:= \033[0;31m
B_GREEN	:= \033[1;32m
GREEN 	:= \033[0;33m
B_BLUE 	:= \033[1;34m
BLUE 	:= \033[0;34m
PURPLE	:= \033[0;35m
WHCOLOR	:= \033[0;40m

all: $(SUBM_FLAG)  printf libft  $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@echo "____!!!$(BLUE)----- Compiling Libft------$(NC)"
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBFT) bonus
	@echo "Compilation of Libft:	\033[1;32mOK\033[m"

printf:
	@echo "____!!!$(BLUE)----- Compiling Printf------$(NC)"
	@$(MAKE) -C $(PRINTF)
	@echo "Compilation of Printf:	\033[1;32mOK\033[m"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) $(PRINTF_DIR) $(LIBFT)libft.a -o  $(NAME)
	@echo "Compilation of Pipex:	\033[1;32mSUCCESS\033[m"

# Clean up your trashes 

clean:
	@echo "$(GREEN)♻️ ${B_RED} Trashing Away objects..... $(GREEN)♻️ "
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean
	@sleep 0.5
	@echo "	$(B_RED) Cleaning Done $(NC)"

fclean: clean
	@rm -f $(NAME) 
	@echo "$(GREEN)♻️ ${B_RED} Trashing Away all objects and library...."
	
re: fclean all

.phony: all libft clean fclean
