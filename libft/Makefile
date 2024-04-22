# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kro <kro@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 19:29:48 by aandrieu          #+#    #+#              #
#    Updated: 2023/08/30 11:09:57 by kro              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strlen ft_numbers ft_printf ft_words

SRCS = $(addsuffix .c, ${SRC})

OBJS = ${SRCS:.c=.o}

FLAG = -Wall -Wextra -Werror

.c.o:
		gcc ${FLAG} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		ar rc $(NAME) ${OBJS}
		ranlib $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
