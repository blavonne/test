NAME = libftprintf.a
NAME_E = printf
FLAGS = -Wall -Werror -Wextra
INCLUDES = ./includes/
SRC_DIR = ./srcs/
L_ROOT = ../libft/
LIBFT = libft.a
L_FLAGS = -L $(L_ROOT) -lft
FLOAT_DIR = ./floats/

SRC =	$(FLOAT_DIR)big_math_b2b.c\
		$(FLOAT_DIR)big_math_b2n.c\
		$(FLOAT_DIR)frac_math.c\
		$(FLOAT_DIR)fractional_base.c\
		$(FLOAT_DIR)fractional_to_str.c\
		$(FLOAT_DIR)get_mant_len.c\
		$(FLOAT_DIR)initialize_float.c\
		$(FLOAT_DIR)integral_base.c\
		$(FLOAT_DIR)integral_creation.c\
		$(FLOAT_DIR)integral_to_str.c\
		$(SRC_DIR)chars_conversion.c\
		$(SRC_DIR)chars_printing.c\
		$(SRC_DIR)check_info.c\
		$(SRC_DIR)float_conversion.c\
		$(SRC_DIR)float_flags_cases.c\
		$(SRC_DIR)float_get_arg.c\
		$(SRC_DIR)integer_flags_cases.c\
		$(SRC_DIR)integer_conversion.c\
		$(SRC_DIR)integer_printing.c\
		$(SRC_DIR)integer_sign_prefix.c\
		$(SRC_DIR)nbr_len.c\
		$(SRC_DIR)nbr_len_iu.c\
		$(SRC_DIR)nbr_len_lu.c\
		$(SRC_DIR)nbr_len_llu.c\
		$(SRC_DIR)parser.c\
		$(SRC_DIR)parser_flags.c\
		$(SRC_DIR)percent_case.c\
		$(SRC_DIR)pointer_conversion.c\
		$(SRC_DIR)printf.c\
		$(SRC_DIR)processor.c\

OS = $(SRC:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(L_ROOT)

$(NAME): $(OS)
	cp $(L_ROOT)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OS)

%.o: %.c $(INCLUDES)printf.h $(INCLUDES)fractional.h $(INCLUDES)xray.h\
$(INCLUDES)integral.h
	gcc -c $< -o $@ -I $(INCLUDES) -I $(L_ROOT) $(FLAGS)

clean:
	rm -rf $(OS)
	make -C $(L_ROOT) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	make -C $(L_ROOT) fclean
re: fclean all

exe: $(NAME)
	gcc -c main.c
	gcc $(OS) main.o -o $(NAME_E) -L -lfrprintf
eclean: clean
	rm -rf main.o
efclean: eclean
	rm -rf $(NAME_E)
ere: efclean exe

.PHONY: all clean fclean re exe eclean efclean
