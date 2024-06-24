NAME = fdf

CC = cc

FLAGS = -g -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux

MLX_LIB = ${MLX_DIR}/libmlx.a

MLX_FLAG = -lm -lmlx -lX11 -lXext

LIBFT_DIR = ./libft-complete

LIBFT_LIB = ${LIBFT_DIR}/libft_complete.a

LIBFT_FLAG = -lft_complete

INCLUDES = -I ./Includes/

SOURCES = ./Sources/main.c\
		  ./Sources/Display/display.c\
		  ./Sources/Event_handler/event_handler.c\
		  ./Sources/Event_handler/key_handler.c\
		  ./Sources/Event_handler/mouse_handler.c\
		  ./Sources/Event_handler/window_handler.c\
		  ./Sources/Image_handler/image_handler.c\
		  ./Sources/Image_handler/color_writing.c\
		  ./Sources/Image_handler/point_drawing.c\
		  ./Sources/Image_handler/line_drawing.c\
		  ./Sources/Utils/utils.c\
		  ./Sources/Utils/file_opener.c\
		  ./Sources/Utils/transform_to_float.c

OBJS = ${SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${MLX_LIB} ${LIBFT_LIB}
	${CC} ${FLAGS} ${OBJS} -L${MLX_DIR} -L${LIBFT_DIR} -o $@ ${MLX_FLAG} ${LIBFT_FLAG}

${MLX_LIB} :
	${MAKE} -C ${MLX_DIR}

${LIBFT_LIB} :
	${MAKE} -C ${LIBFT_DIR}

%.o : %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C ${MLX_DIR}
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${OBJS}

fclean : clean
	${MAKE} clean -C ${MLX_DIR}
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
