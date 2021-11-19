# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 21:12:36 by haitkadi          #+#    #+#              #
#    Updated: 2021/11/15 21:12:44 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
	ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SOURCES = ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c\
	ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SOURCES:%.c=%.o)
BONUS_OBJECTS = $(BONUS_SOURCES:%.c=%.o)

$(NAME) : $(OBJECTS) libft.h
	@ar rcs $(NAME) $(OBJECTS)
	@echo "Created your archive library"

bonus: all $(BONUS_OBJECTS)
	@ar rcs $(NAME) $(BONUS_OBJECTS)
	@echo "Bonus added to your library"

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -c $<
	@echo "Crated .o from .c file"

clean:
	@rm $(OBJECTS)
	@rm $(BONUS_OBJECTS)
	@echo ".o files are cleaned successfuly"

fclean: clean
	@rm $(NAME)
	@echo "Full clean is applaied successfuly"

re: fclean all

.PHONY: all clean fclean re bonus