SRCS = map.c gnl.c utils.c utils2.c display.c error.c events.c utils3.c bonus.c

MAIN = main.c

DIRECTORYS = srcs/

SRCSD =	$(addprefix ${DIRECTORYS}, $(SRCS))

EFLAGS = -Wall -Wextra -Werror

OBJS =	${SRCSD:.c=.o}

HEADER = include/so_long.h

OFLAGS = -c

NAME   = so_long

%.o: %.c ${HEADER}
	gcc ${OFLAGS} ${EFLAGS} -o $@ $<

${NAME}: ${OBJS}
	gcc  -lmlx -framework OpenGL -framework AppKit $(EFLAGS) -o $(NAME) $(MAIN) ${SRCSD}
			
all:	${NAME}

clean:
		rm  -f ${OBJS}

fclean:	clean
		rm  -f ${NAME}
		
mlx:	
	(cd mlx && make)
	make ${NAME}
	

mlxclean : 
	(cd mlx && make clean)
	make fclean

re:		fclean all

.PHONY:	all clean fclean re mlx mlxclean
