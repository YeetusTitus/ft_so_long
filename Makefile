SRCS = main.c

DIRECTORYS = ./

SRCSD =	$(addprefix ${DIRECTORYS}, $(SRCS))

OBJS =	${SRCSD:.c=.o}

EFLAGS = -Wall -Wextra -Werror

HEADER = include/so_long.h

OFLAGS = -c

NAME   = yolo

%.o: %.c ${HEADER}
	gcc -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}: ${OBJS}
	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			
all:	${NAME}

clean:
		rm  -f ${OBJS}

fclean:	clean
		rm  -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re