INC=/usr/include
INCLIB=$(INC)/../libft
INCMYLIB=./libft/
INCCORE=./core/

NAME = push_swap

SRC = $(INCCORE)push_swap.c $(INCCORE)swaps.c $(INCCORE)rotates.c $(INCCORE)reverses.c $(INCCORE)pushs.c $(INCCORE)sorts.c $(INCCORE)inits.c $(INCCORE)errors.c $(INCCORE)split.c $(INCMYLIB)ft_strlen.c $(INCMYLIB)ft_printf.c $(INCMYLIB)ft_numbers.c $(INCMYLIB)ft_words.c

FLAG = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -g $(FLAG) -o $(NAME) $(OBJ)

clean:
	rm -rf *.o
	rm -rf $(INCMYLIB)*.o
	rm -rf $(INCCORE)*.o

fclean:
	rm -rf $(NAME)
	rm -rf *.o
	rm -rf $(INCMYLIB)*.o
	rm -rf $(INCCORE)*.o

re: clean all
