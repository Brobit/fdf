NAME = fdf

CC = cc

FLAGS = -g -Wall -Wextra -Werror

MLX_LIB = ./minilibx-linux/libmlx.a

MLX_FLAG = -lm -lmlx -lXext -lX11

INCLUDES = -I ./Includes/

SOURCES = ./Sources/

OBJS = ${SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${MLX_LIB}
	${CC} ${FLAGS} ${MLX_FLAG} -L${MLX_LIB} ${SOURCES} ${INCLUDES} -o $@

${MLX_LIB} :
	${MAKE} -C $$(dirname ${MLX_LIB})

%.o : %.c
	${CC} ${FLAGS} ${MLX_FLAG} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C $$(dirname ${MLX_LIB})
	${RM} ${OBJS}

fclean : clean
	${MAKE} clean -C $$(dirname ${MLX_LIB})
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
