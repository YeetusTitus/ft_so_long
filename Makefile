SRCS = map.c gnl.c utils.c utils2.c display.c error.c events.c utils3.c loop.c

MAIN = main.c

DIRECTORYS = srcs/

SRCSD =	$(addprefix ${DIRECTORYS}, $(SRCS))

EFLAGS = -Wall -Wextra -Werror

HEADER = include/so_long.h

OFLAGS = -c

NAME   = so_long

${NAME}: 
	gcc  -lmlx -framework OpenGL -framework AppKit $(EFLAGS) -o $(NAME) $(MAIN) ${SRCSD}
			
all:	${NAME}

clean:
		rm  -f ${OBJS}

fclean:	clean
		rm  -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re