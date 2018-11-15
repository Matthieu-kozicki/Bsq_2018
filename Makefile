##
## EPITECH PROJECT, 2018
## make
## File description:
## no
##

SRC	=	my_putstr.c \
		my_strlen.c \
		my_putchar.c \
		my_put_nbr.c \
		get_line.c

SRCM	=	main.c

OBJ	=	$(SRC:.c=.o)

OBJM	=	$(SRCM:.c=.o)

NAME	=	bsq

INCLUDE	=	 -I include/

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJM)
	gcc -o $(NAME) $(OBJ) $(OBJM) $(INCLUDE)
clean:
	rm -f $(OBJ)
	rm -f $(OBJM)
	rm -f */*.gc*
	rm -f *~

%.o: %.c
	gcc -o $@ -c $< -I include/

fclean: clean
	rm -f $(NAME)

re: fclean
	rm -f all
