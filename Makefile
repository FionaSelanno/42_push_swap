SRCS =		main.c\
			input_handler.c\
			arr_functions.c\
			list_functions.c\
			sort_functions.c\
			big_sort.c\
			sort_operations_1.c\
			sort_operations_2.c\
			sort_operations_3.c\
			utils.c

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
