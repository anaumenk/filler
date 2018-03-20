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

SWITCH =		\033[
ST_NORM =		$(SWITCH)0m
COLOR_GREEN =	$(SWITCH)42m
COLOR_RED =		$(SWITCH)41m
COLOR_SGREEN =	$(SWITCH)35m
NAME =			anaumenk.filler
FLAGS =			-c -Wall -Wextra -Werror
C_FILES =		filler.c find_and_fill.c
O_FILES =		$(C_FILES:.c=.o)
HEADER =		filler.h

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libftprintf/
	@gcc -o $(NAME) $(O_FILES) libftprintf/libftprintf.a
	@echo "$(STYLE_BOLD)$(COLOR_GREEN) anaumenk.filler has been compiled.$(ST_NORM)"

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -o $@ $<

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
