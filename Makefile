# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kle <dvan-kle@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/26 14:40:46 by dvan-kle      #+#    #+#                  #
#    Updated: 2022/11/04 19:19:51 by dvan-kle      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

C=gcc

NAME=libftprintf.a

CFLAGS=-Wall -Werror -Wextra

SRC=	ft_printf.c \
		ft_address.c \
		ft_funcs.c \
		ft_hexa.c \
		ft_uns_int.c 

OBJ=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(C) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all	

.PHONY: clean fclean all re