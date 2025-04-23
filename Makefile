##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile function
##

SRC	=			main.c										\
				src/wolf.c									\
				src/init/init_main.c 						\
				src/init/init_map.c 						\
				src/init/init_player.c 						\
				src/init/init_sprite.c 						\
				src/init/init_window.c 						\
				src/init/init_background.c 					\
				src/init/init_text_start.c       			\
				src/init/init_text_quit.c       			\
				src/init/init_object.c		       			\
				src/display/display_loop.c 					\
				src/display/display_main.c 					\
				src/destroy/destroy_function.c				\
				src/destroy/destroy_window_menu.c 			\
				src/menu/display_menu_loop.c 				\
				src/menu/init_menu.c 						\
				src/menu/menu.c 							\
				src/menu/update_menu.c						\
				src/display/ray_casting/cast_all_rays.c 	\
				src/display/ray_casting/cast_single_ray.c 	\
				src/display/ray_casting/deg_to_rad.c		\
				src/display/ray_casting/render_wall_column.c\
				src/is_wall.c								\
				src/display/draw_player.c

CFLAGS	+= -g

NAME    =	wolf3d

all: make_lib $(NAME)

make_lib:
	@$(MAKE) -C lib > /dev/null

$(NAME): $(SRC)
	@gcc -g -o $(NAME)												\
	$(SRC)																\
	lib/libmy.a -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio \
	-Wall -Wextra -lm -I include/

clean:
	@rm -f lib/my/*.o
	@rm -f lib/my/*~
	@rm -f lib/my/#*#
	@rm -f lib/my/flags/*.o
	@rm -f lib/my/flags/*~
	@rm -f lib/my/flags/#*#
	@rm -f lib/my/sous_flag/*.o
	@rm -f lib/my/sous_flag/*~
	@rm -f lib/my/sous_flag/#*#
	@rm -f *.o
	@rm -f *~
	@rm -f #*#

fclean:	clean
	@rm -f $(NAME)
	@rm -f lib/libmy.a

re:	fclean all


.PHONY: all clean fclean re
