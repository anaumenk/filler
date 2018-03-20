# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/16 16:18:22 by anaumenk          #+#    #+#              #
#    Updated: 2018/03/16 16:18:24 by anaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH =        \033[
STYLE_NORMAL =  $(SWITCH)0m
STYLE_BOLD =    $(SWITCH)1m
COLOR_YELLOW =  $(SWITCH)93m
COLOR_GREEN =   $(SWITCH)34m
COLOR_RED =     $(SWITCH)31m

C_FILES =  ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c \
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_tolower.c ft_toupper.c \
get_next_line.c \
color.c findout.c flags.c for_big_s_ls.c for_c.c for_id.c for_n.c \
for_ou.c /for_sp.c for_x.c ft_printf.c ft_pstrjoin.c unicode.c

O_FILES = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o \
ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o \
ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o \
ft_memset.o ft_putchar_fd.o ft_putchar.o ft_putendl_fd.o ft_putendl.o \
ft_putnbr_fd.o ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strcat.o \
ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o \
ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o \
ft_strtrim.o ft_tolower.o ft_toupper.o \
get_next_line.o \
color.o findout.o flags.o for_big_s_ls.o for_c.o for_id.o for_n.o \
for_ou.o for_sp.o for_x.o ft_printf.o ft_pstrjoin.o unicode.o

FLAGS = -Wall -Wextra -Werror

all: $(addprefix ../objects/,$(O_FILES))

../objects/%.o: %.c
	@echo "$(STYLE_BOLD)$(COLOR_GREEN) $< has been compiled.$(STYLE_NORMAL)"
	@gcc -c $(FLAGS) $<  -I ../include -o $@ 

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All the object files\
	have been deleted.$(STYLE_NORMAL)"
	@rm -rf $(addprefix ../objects/,$(O_FILES))

fclean: clean
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"

re: fclean all

.PHONY: clean all fclean re
