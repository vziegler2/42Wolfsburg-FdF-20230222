SRCS	=	./Libft/Libft.a ./MiniLibX/libmlx.a
SRCS_C	=	fdf.c ft_print_error.c ft_height.c ft_free_arr.c ft_close.c ft_put.c ft_dots.c ft_fill.c ft_escape.c ft_dots2.c ft_draw.c ft_settings.c ft_settings2.c ft_input.c ft_click.c ft_fill2.c
# Hier alle zu kompilierenden Dateien erfassen
OBJS_C	=	${SRCS_C:.c=.o}
# Damit nur veränderte .c-Dateien in .o-Dateien kompiliert werden
NAME	=	fdf
MAKELIB =	./Libft/Libft.a
MAKEMIN =	./MiniLibX/libmlx.a
# Namen der kompilierten Programme
RM		=	rm -f
# -f (force) macht fclean jederzeit ausführbar (auch ohne .o-Dateien)
CC		=	cc
# Kompiliersprache
CFLAGS	=	-Wall -Wextra -Werror
# Die verwendeten Flags
FRAMES	=	-framework OpenGL -framework AppKit
# Die verwendeten Frameworks
all:		${MAKELIB} ${MAKEMIN} ${NAME}
# Damit nur bei Veränderungen neu kompiliert wird
${MAKELIB}:	
			make -C Libft
${MAKEMIN}:	
			make -C MiniLibX
${NAME}:	${OBJS_C}
			${CC} ${CFLAGS} -o $@ $^ ${SRCS} ${FRAMES}
# Die .o-Dateien werden nur verlinkt, falls NAME noch nicht existiert
clean:
			${RM} ${OBJS_C}
# Löscht die .a-Dateien
fclean:		clean
			${RM} ${NAME}
			make -C Libft fclean && make -C MiniLibX clean
# Führt die fclean-Befehle der Unterordner aus und entfernt die .exe
re:			fclean all
# Löscht und rekompiliert
.PHONY:		all clean fclean re
# Führt die Befehle aus, auch wenn eine gleichnamige Datei existiert