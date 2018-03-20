# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 16:52:17 by anaumenk          #+#    #+#              #
#    Updated: 2018/03/16 16:52:19 by anaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH =        \033[
ST_NORM =  		$(SWITCH)0m
COLOR_GREEN =   $(SWITCH)42m
COLOR_RED =     $(SWITCH)41m
COLOR_SGREEN = 	$(SWITCH)35m
NAME = 			anaumenk.filler
FLAGS = -Wall -Wextra -Werror
C_FILES = filler.c find_and_fill.c
O_FILES = filler.o find_and_fill.o

all: $(NAME)

$(NAME):
	@make -C libftprintf
	@gcc -c $(FLAGS) $(C_FILES)
	@gcc $(FLAGS) $(O_FILES) libftprintf/libftprintf.a -o $(NAME)
	@echo "$(STYLE_BOLD)$(COLOR_GREEN) anaumenk.filler has been compiled.$(ST_NORM)"

clean:
	@make clean -C libftprintf
	@rm -rf $(O_FILES)
	@echo "$(STYLE_BOLD)$(COLOR_RED)DIR objects have been deleted.$(ST_NORM)"

fclean: clean
	@make fclean -C libftprintf
	@rm -rf $(NAME)
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(ST_NORM)"

re: fclean all
	
.PHONY: clean all fclean re
