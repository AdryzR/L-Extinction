##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile function
##

SRC 	=	lib/my/concat_params.c				\
			lib/my/my_isneg.c					\
			lib/my/my_rev_list.c 				\
			lib/my/my_show_word_array.c			\
			lib/my/my_str_islower.c				\
			lib/my/my_strncpy.c					\
			lib/my/my_is_prime.c				\
			lib/my/my_sort_int_array.c			\
			lib/my/my_str_isnum.c				\
			lib/my/my_strstr.c					\
			lib/my/my_putchar.c					\
			lib/my/my_strcapitalize.c			\
			lib/my/my_str_isprintable.c			\
			lib/my/my_str_to_word_array.c		\
			lib/my/my_compute_power_rec.c		\
			lib/my/my_put_nbr.c					\
			lib/my/my_strcat.c					\
			lib/my/my_str_isupper.c				\
			lib/my/my_strupcase.c				\
			lib/my/my_compute_square_root.c		\
			lib/my/my_putstr.c					\
			lib/my/my_strcmp.c					\
			lib/my/my_strlen.c					\
			lib/my/my_swap.c					\
			lib/my/my_find_prime_sup.c			\
			lib/my/my_revstr.c					\
			lib/my/my_strcpy.c					\
			lib/my/my_strlowcase.c				\
			lib/my/my_getnbr.c					\
			lib/my/my_showmem.c					\
			lib/my/my_strdup.c					\
			lib/my/my_strncat.c					\
			lib/my/my_showstr.c					\
			lib/my/my_str_isalpha.c				\
			lib/my/my_strncmp.c					\
			lib/my/my_shows_param_array.c		\
			lib/my/my_list_size.c				\
			lib/my/my_printf.c 					\
			lib/my/my_char_isnum.c				\
			lib/my/flags/flag_c.c 				\
			lib/my/flags/flag_i_d.c 			\
			lib/my/flags/flag_pourcent.c 		\
			lib/my/flags/flag_s.c 				\
			lib/my/flags/flag_u.c				\
			lib/my/flags/flag_a.c				\
			lib/my/flags/flag_upper_a.c			\
			lib/my/flags/flag_e.c				\
			lib/my/flags/flag_upper_e.c			\
			lib/my/flags/flag_f.c				\
			lib/my/flags/flag_upper_f.c 		\
			lib/my/flags/flag_g.c				\
			lib/my/flags/flag_upper_g.c			\
			lib/my/flags/flag_o.c				\
			lib/my/flags/flag_p.c				\
			lib/my/flags/flag_x.c				\
			lib/my/flags/flag_upper_x.c			\
			lib/my/flags/flag_upper_s.c 		\
			lib/my/sous_flag/sf_space.c			\
			lib/my/sous_flag/sf_plus.c 			\
			lib/my/sous_flag/sf_hashtag.c

SRC_C	=		main.c										\
				src/manage_script/open_script.c 			\
				src/init/init_background.c 					\
				src/init/init_entity.c 						\
				src/init/init_main.c 						\
				src/init/init_sprite.c 						\
				src/init/init_object.c 						\
				src/init/init_window.c 						\
				src/destroy/destroy_function.c				\
				src/display/display_loop.c   				\
				src/display/display_text.c 					\
				src/display/display_main.c 					\
				src/display/display_window.c 				\
				src/display/display_entity.c				\
				src/display/display_plane_bottomleft.c		\
				src/display/display_plane_topleft.c		\
				src/display/display_plane_bottomright.c	\
				src/display/display_plane_topright.c		\
				src/update/update_plane.c					\
				src/update/update_timer.c					\
				src/update/update_tower.c					\
				src/list/delete_function.c					\
				src/list/move_data.c						\
				src/init/init_player.c						\
				src/init/init_map.c

CFLAGS	+= -g

NAME    =	wolf3d

OBJ 	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(SRC_C)
	@ar rc libmy.a $(OBJ)
	@gcc -g -o $(NAME) 														\
	$(SRC_C)																\
	libmy.a -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio	\
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
	@rm -f libmy.a

re:	fclean all


.PHONY: all clean fclean re unit_tests test_run
