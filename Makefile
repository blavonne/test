
# ft_checker variables----------------------------------------------------------
CHECKER = checker
C_ROOT = ./ft_checker/
C_SRCS = $(C_ROOT)srcs/
C_INC = $(C_ROOT)includes/
# libft  variables--------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_FLAGS = -L $(L_ROOT) -lft
# printf variables--------------------------------------------------------------
PRINTF = ./printf/libftprintf.a
P_ROOT = ./printf/
P_INC = $(P_ROOT)includes/
P_FLAGS = -L $(P_ROOT) -lftprintf

SRC = $(C_SRCS)bigint_base.c\
	$(C_SRCS)commander.c\
	$(C_SRCS)errors.c\
	$(C_SRCS)reader.c\
	$(C_SRCS)stack_handler.c\
	$(C_ROOT)checker.c\

OBJ = $(SRC:%.c=%.o)

# flags-------------------------------------------------------------------------
FLAGS = -Wall -Werror -Wextra
I_FLAGS = -I $(C_INC) -I $(P_INC) -I $(L_ROOT)

all: $(CHECKER)
# build external libraries------------------------------------------------------
$(LIBFT):
	$(MAKE) -C $(L_ROOT)
$(PRINTF):
	$(MAKE) -C $(P_ROOT)

# build checker-----------------------------------------------------------------
$(CHECKER): $(OBJ) $(LIBFT) $(PRINTF) $(C_INC)checker.h
	gcc $(OBJ) -o checker $(I_FLAGS) $(FLAGS) $(L_FLAGS) $(P_FLAGS)
%.o: %.c $(C_INC)checker.h
	gcc -c $< -o $@ $(I_FLAGS) $(FLAGS) $(L_FLAGS) $(P_FLAGS)

# clean section-----------------------------------------------------------------
clean:
	$(MAKE) -C $(L_ROOT) clean
	$(MAKE) -C $(P_ROOT) clean
	rm -rf $(OBJ)
fclean: clean
	$(MAKE) -C $(L_ROOT) fclean
	$(MAKE) -C $(P_ROOT) fclean
	rm -rf $(CHECKER)
re: fclean all
