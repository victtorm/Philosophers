PHILO_FILES = main.c check.c start_data.c
OBJS = ${PHILO_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = philo

all:		${NAME}

${NAME}:	${OBJS} ${LIBFTA}
			${CC} ${CFLAGS} $(OBJS) ${LIBFTA} -o ${NAME}

${LIBFTA}:	${LIBFTD}
		make -C ${LIBFTD}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
