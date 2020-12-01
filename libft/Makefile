# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 14:47:24 by eprusako          #+#    #+#              #
#    Updated: 2020/12/01 12:12:42 by eprusako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

HDDIRS=-I ./

CC = @gcc -g

AR = @ar rc

RUN = @ranlib

SRC =	ft_bzero.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_putchar.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memset.c  \
		ft_bzero.c  \
		ft_memcpy.c  \
		ft_memccpy.c  \
		ft_memmove.c  \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strnew.c \
		ft_strclr.c \
		ft_strdel.c \
		ft_memdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strjoin.c \
		ft_strcharjoin.c \
		ft_strjoinfree.c \
		ft_strsub.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_strrchr.c \
		ft_strmapi.c \
		ft_strmap.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_isupper.c \
		ft_islower.c \
		ft_lstfindnode.c \
		ft_lstpushback.c \
		ft_lst_len.c \
		ft_isspace.c \
		ft_itoa_base.c \
		get_next_line.c \
		ft_abs.c \
		ft_mod.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	$(AR) $(NAME) $(OBJ)
	$(RUN) $(NAME)
	@echo "\033[32mBuilt library.\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32mCleaned up object files.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mCleaned up compiled files.\033[0m"

re: fclean all

.PHONY: all clean fclean re
