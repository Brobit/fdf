NAME = fdf

CC = cc

FLAGS = -g -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux

MLX_LIB = ${MLX_DIR}/libmlx.a

MLX_FLAG = -lm -lmlx -lX11 -lXext

INCLUDES = -I ./Includes/

SOURCES = ./Sources/main.c\
		  ./Sources/Display/display.c\
		  ./Sources/Event_handler/event_handler.c\
		  ./Sources/Event_handler/key_handler.c\
		  ./Sources/Event_handler/mouse_handler.c\
		  ./Sources/Event_handler/window_handler.c\
		  ./Sources/Image_handler/image_handler.c

OBJS = ${SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${MLX_LIB}
	${CC} ${FLAGS} ${OBJS} -L${MLX_DIR} -o $@ ${MLX_FLAG}

${MLX_LIB} :
	${MAKE} -C ${MLX_DIR}

%.o : %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C ${MLX_DIR}
	${RM} ${OBJS}

fclean : clean
	${MAKE} clean -C ${MLX_DIR}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
