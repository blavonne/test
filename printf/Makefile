NAME = libftprintf.a
NAME_E = printf
FLAGS = -Wall -Werror -Wextra
INCLUDES = ./includes/
SRCSDIR = ./srcs/
LIBFTDIR = ../libft/
FLTDIR = ./floats/

SRC =	$(FLTDIR)big_math_b2b.c\
		$(FLTDIR)big_math_b2n.c\
		$(FLTDIR)frac_math.c\
		$(FLTDIR)fractional_base.c\
		$(FLTDIR)fractional_to_str.c\
		$(FLTDIR)get_mant_len.c\
		$(FLTDIR)initialize_float.c\
		$(FLTDIR)integral_base.c\
		$(FLTDIR)integral_creation.c\
		$(FLTDIR)integral_to_str.c\
		$(LIBFTDIR)errors.c\
		$(LIBFTDIR)ft_abs.c\
		$(LIBFTDIR)ft_bzero.c\
		$(LIBFTDIR)ft_isdigit.c\
		$(LIBFTDIR)ft_itoa.c\
		$(LIBFTDIR)ft_itoa_lu.c\
		$(LIBFTDIR)ft_itoa_llu.c\
		$(LIBFTDIR)ft_memset.c\
		$(LIBFTDIR)ft_pow.c\
		$(LIBFTDIR)ft_putchar.c\
		$(LIBFTDIR)ft_putstr.c\
		$(LIBFTDIR)ft_putstr_fd.c\
		$(LIBFTDIR)ft_str_tolower.c\
		$(LIBFTDIR)ft_str_toupper.c\
		$(LIBFTDIR)ft_strcat.c\
		$(LIBFTDIR)ft_strchr.c\
		$(LIBFTDIR)ft_strcpy.c\
		$(LIBFTDIR)ft_strjoin.c\
		$(LIBFTDIR)ft_strlen.c\
		$(LIBFTDIR)ft_strnew.c\
		$(LIBFTDIR)ft_tolower.c\
		$(LIBFTDIR)ft_toupper.c\
		$(SRCSDIR)chars_conversion.c\
		$(SRCSDIR)chars_printing.c\
		$(SRCSDIR)check_info.c\
		$(SRCSDIR)float_conversion.c\
		$(SRCSDIR)float_flags_cases.c\
		$(SRCSDIR)float_get_arg.c\
		$(SRCSDIR)integer_flags_cases.c\
		$(SRCSDIR)integer_conversion.c\
		$(SRCSDIR)integer_printing.c\
		$(SRCSDIR)integer_sign_prefix.c\
		$(SRCSDIR)nbr_len.c\
		$(SRCSDIR)nbr_len_iu.c\
		$(SRCSDIR)nbr_len_lu.c\
		$(SRCSDIR)nbr_len_llu.c\
		$(SRCSDIR)parser.c\
		$(SRCSDIR)parser_flags.c\
		$(SRCSDIR)percent_case.c\
		$(SRCSDIR)pointer_conversion.c\
		$(SRCSDIR)printf.c\
		$(SRCSDIR)processor.c\

OS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OS) $(INCLUDES)printf.h $(INCLUDES)fractional.h $(INCLUDES)xray.h\
$(INCLUDES)integral.h
	ar rcs $(NAME) $(OS)
%.o: %.c $(INCLUDES)printf.h $(INCLUDES)fractional.h $(INCLUDES)xray.h\
$(INCLUDES)integral.h
	gcc -c $< -o $@ -I $(INCLUDES) $(FLAGS)
clean:
	rm -rf $(OS)
fclean: clean
	rm -rf $(NAME)
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
