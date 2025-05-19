##
## EPITECH PROJECT, 2024
## G-ING-210-STG-2-1-wolf3d-mateo.antoni-christ
## File description:
## Makefile
##

GREEN          = \033[1;32m
RED            = \033[1;31m
ILC      	   = \033[3m
ORANGE         = \033[38;5;214m
RST            = \033[0m

SRC 	=	my/concat_params.c					\
			my/my_isneg.c						\
			my/my_rev_list.c 					\
			my/my_show_word_array.c				\
			my/my_str_islower.c					\
			my/my_strncpy.c						\
			my/my_is_prime.c					\
			my/my_sort_int_array.c				\
			my/my_str_isnum.c					\
			my/my_strstr.c					 	\
			my/my_putchar.c						\
			my/my_strcapitalize.c				\
			my/my_str_isprintable.c				\
			my/my_str_to_word_array.c			\
			my/my_compute_power_rec.c			\
			my/my_put_nbr.c						\
			my/my_strcat.c						\
			my/my_str_isupper.c					\
			my/my_strupcase.c					\
			my/my_compute_square_root.c			\
			my/my_putstr.c						\
			my/my_strcmp.c						\
			my/my_strlen.c						\
			my/my_swap.c						\
			my/my_find_prime_sup.c				\
			my/my_revstr.c						\
			my/my_strcpy.c						\
			my/my_strlowcase.c					\
			my/my_getnbr.c						\
			my/my_showmem.c						\
			my/my_strdup.c						\
			my/my_strncat.c						\
			my/uint_to_str.c					\
			my/my_showstr.c						\
			my/my_str_isalpha.c					\
			my/my_strncmp.c						\
			my/my_shows_param_array.c			\
			my/my_list_size.c					\
			my/my_printf.c 						\
			my/my_char_isnum.c					\
			my/flags/flag_c.c 					\
			my/flags/flag_i_d.c 				\
			my/flags/flag_pourcent.c 			\
			my/flags/flag_s.c 					\
			my/flags/flag_u.c					\
			my/flags/flag_a.c					\
			my/flags/flag_upper_a.c				\
			my/flags/flag_e.c					\
			my/flags/flag_upper_e.c				\
			my/flags/flag_f.c					\
			my/flags/flag_upper_f.c 			\
			my/flags/flag_g.c					\
			my/flags/flag_upper_g.c				\
			my/flags/flag_o.c					\
			my/flags/flag_p.c					\
			my/flags/flag_x.c					\
			my/flags/flag_upper_x.c				\
			my/flags/flag_upper_s.c 			\
			my/sous_flag/sf_space.c				\
			my/sous_flag/sf_plus.c 				\
			my/sous_flag/sf_hashtag.c			\
			my/my_realloc.c 					\
			my/my_strndup.c 					\
			my/my_str_isalphanum.c				\
			my/my_memcpy.c						\
			my/safe_string_parsing.c 			\
			my/safe_fopen.c						\
			my/free_tab.c  						\
			my/delete_node.c					\
			my/free_linklist.c 					\
			my/push_to_end_list.c 				\
			my/print_tab.c						\
			my/push_to_begin_list.c				\
			my/pop_front.c 						\
			my/pop_back.c


OBJ 	=	$(SRC:.c=.o)

CFLAGS	+= -g

NAME    =	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "$(GREEN)[✅] COMPILED: $(RST) $(ILC)$(NAME)$(RST)\n"

.PHONY: all
.SILENT:
