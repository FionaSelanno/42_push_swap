SRCS =		input_handler.c\
			list_handler.c\
			list_handler2.c\
			arr_handler.c\
			small_sort.c\
			big_sort.c\
			ft_split.c\
			operations_1.c\
			operations_2.c\
			operations_3.c\
			utils.c\
			utils2.c\
			utils3.c\
			utils4.c\
			main.c\

OBJS = 		${SRCS:.c=.o}

NAME = 		push_swap

FLAGS =		-Wall -Wextra -Werror -g

.c.o:		
			gcc ${FLAGS} -I push_swap.h -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
				rm -rf ${OBJS}

fclean:		clean
				rm -f ${NAME}

re: 		fclean all	

.PHONY:		fclean clean all re
