##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile function
##

GREEN          = \033[1;32m
RED            = \033[1;31m
ILC      	   = \033[3m
ORANGE         = \033[38;5;214m
RST            = \033[0m

SRC	=			main.c										\
				src/wolf.c									\
				src/init/init_main.c 						\
				src/init/init_map.c 						\
				src/init/init_player.c 						\
				src/init/init_sprite.c 						\
				src/init/init_window.c 						\
				src/init/init_background.c 					\
				src/init/init_other.c 						\
				src/init/init_button_start.c       			\
				src/init/init_button_quit.c       			\
				src/init/init_weapons.c       				\
				src/init/init_object.c		       			\
				src/init/init_music.c		       			\
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
				src/is_entity.c								\
				src/display/draw_player.c					\
				src/display/ui/draw_ui.c					\
				src/display/ui/reload.c						\
				src/display/ui/is_mag_empty.c				\
				src/display/ui/update_ak.c					\
				src/display/ui/update_ui.c					\
				src/display/ui/update_hp.c					\
				src/display/ui/update_gun.c					\
				src/display/ui/update_weapon_texture.c		\
				src/display/ui/add_ammo_drop.c				\
				src/display/check_collision.c 				\
				src/settings/settings.c 					\
				src/init/create_button.c 					\
				src/display/ray_casting/rad_to_deg.c 		\
				src/init/init_npc.c							\
				src/display/draw_fog.c						\
				src/display/draw_sprite.c					\
				src/destroy/destroy_texture.c				\
				src/display/draw_npc.c						\
				src/check_npc_hit.c							\
				src/check_death_npc.c						\
				src/move_npc.c								\
				src/display/manage_npc.c					\
				src/add_particle.c 							\
				src/update_particle.c 						\
				src/settings/settings_button.c 				\
				src/display/manage_fullscreen.c				\
				src/display/pickup_drops.c					\
				src/display/draw_ammo.c						\
				src/destroy/free_particle.c					\
				src/display/draw_ammo_map.c 				\

CFLAGS	+= -g O3

NAME    =	wolf3d

all: make_lib $(NAME)

make_lib:
	@$(MAKE) -C lib

$(NAME): $(SRC)
	@gcc -g -o $(NAME)												\
	$(SRC)																\
	lib/libmy.a -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio \
	-Wall -Wextra -lm -I include/
	@printf "$(GREEN)[✅] COMPILED: $(RST) $(ILC)$(NAME)$(RST)\n"

clean:
	@rm -f lib/my/*.o
	@rm -f lib/my/*~
	@rm -f lib/my/#*#
	@rm -f lib/my/flags/*.o
	@rm -f lib/my/flags/*~
	@rm -f lib/my/flags/#*#p
	@rm -f lib/my/sous_flag/*.o
	@rm -f lib/my/sous_flag/*~
	@rm -f lib/my/sous_flag/#*#
	@rm -f *.o
	@rm -f *~
	@rm -f #*#
	@printf "$(RED)[❌] CLEAN:    $(RST) Removed $(ILC)objects$(RST)\n"

fclean:	clean
	@rm -f $(NAME)
	@rm -f lib/libmy.a
	@printf "$(RED)[❌] FCLEAN:   $(RST) Removed $(ILC)executables$(RST)\n"

re:	fclean all


.PHONY: all clean fclean re
.SILENT:
