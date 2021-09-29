SRCS	=	main.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			map/map_checker.c \
			map/map_error_handler.c \
			map/map_utils.c \
			map/ft_find_extension.c \
			game/game_functions.c \
			game/game_draw.c \

BONUS	=	bonus/main_bonus.c \
			bonus/game_bonus/game_functions_bonus.c \
			bonus/game_bonus/game_draw_bonus.c \
			bonus/map_bonus/ft_find_extension_bonus.c \
			bonus/map_bonus/map_checker_bonus.c \
			bonus/map_bonus/map_error_handler_bonus.c \
			bonus/map_bonus/map_utils_bonus.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			bonus/game_bonus/game_show_steps_bonus.c \
			bonus/game_bonus/game_over_bonus.c \
			bonus/game_bonus/game_update_frame_bonus.c


OBJS	= $(patsubst %.c, %.o,$(SRCS))

OBJBNS	= $(patsubst %.c, %.o,$(BONUS))

NAME 	= so_long

NAMEBNS = so_long_bonus

GCC		= gcc
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror
LIBFT	= libft/libft.a

HDR		=	so_long.h

UTILHDR	=	libft/libft.h \
			get_next_line/get_next_line.h

HDRBNS	=	bonus/so_long_bonus.h

all:		${NAME}

libmake:	
			@make -C libft/


%.o :		%.c ${HDR}
			@${GCC} ${CFLAGS} -c $< -o $@

${LIBFT}:	libmake

${NAME}:	${LIBFT} ${OBJS} ${HDR} ${UTILHDR}
			@echo "Assembling the project..."
			@${GCC} ${CFLAGS} ${LIBFT} -I /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
			@echo "The program is ready!\n"
			@echo "To use, run: ./so_long map.ber \n"

${NAMEBNS}:	${LIBFT} ${OBJBNS} ${HDRBNS} ${UTILHDR}
			@echo "Assembling the project..."
			@${GCC} ${CFLAGS} ${LIBFT} -I /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit ${OBJBNS} -o ${NAMEBNS}
			@echo "The program is ready!\n"
			@echo "To use, run: ./so_long_bonus map.ber \n" 

clean:		
			@echo "Cleaning the project..."
			@${RM} ${OBJS}
			@${RM} ${OBJBNS}
			@echo "Cleaned the project folder.\n"
			@make clean -C libft/

fclean:
			@echo "Cleaning the project..."
			@${RM} ${OBJS}
			@${RM} ${OBJBNS} 
			@echo "Cleaned the project folder.\n"
			@echo "Removing the program..."
			@${RM} ${NAME}
			@${RM} ${NAMEBNS} 
			@echo "Program removed successfully.\n"
			@make fclean -C libft/

re:			fclean all

bonus:		${LIBFT} ${OBJBNS} ${HDRBNS} ${UTILHDR}
			@echo "Assembling the project..."
			@${GCC} ${CFLAGS} ${LIBFT} -I /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit ${OBJBNS} -o ${NAMEBNS}
			@echo "The program is ready!\n"
			@echo "To use, run: ./so_long_bonus map.ber \n" 

launch:	${NAMEBNS}
			@./so_long_bonus levels/map_valid_bonus.ber			

.PHONY:		re fclean clean libmake all launch bonus