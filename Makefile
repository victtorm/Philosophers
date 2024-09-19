PHILO_FILES = main.c check.c start_data.c start_dinner.c utils.c routine.c \
				acts.c
OBJS = ${PHILO_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = philo

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $(OBJS) -o ${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
