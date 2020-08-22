# ft_checker variables----------------------------------------------------------
CHECKER = checker
C_ROOT = ./ft_checker/
C_SRCS = $(C_ROOT)srcs/
# libft  variables--------------------------------------------------------------
LIBFT = ./libft/libft.a
L_ROOT = ./libft/
L_FLAGS = -L $(L_ROOT) -lft
# printf variables--------------------------------------------------------------
PRINTF = ./printf/libftprintf.a
P_ROOT = ./printf/
P_INC = $(P_ROOT)includes/
P_FLAGS = -L $(P_ROOT) -lftprintf
# push_swap variables-----------------------------------------------------------
PUSH_SWAP = push_swap
PS_ROOT = ./ft_push_swap/
PS_SRCS = $(PS_ROOT)srcs/
PS_INC = ./includes/

C_SRC = $(C_SRCS)bigint_base.c\
	$(C_SRCS)commander.c\
	$(C_SRCS)reader.c\
	$(C_SRCS)stack_handler.c\
	$(C_SRCS)checker.c\
	$(PS_SRCS)cleaner.c\
	$(PS_SRCS)check_order.c\
	$(C_SRCS)spliter.c\
	$(C_ROOT)main.c\

PS_SRC = $(PS_SRCS)all_to_a.c\
	$(PS_SRCS)all_to_b.c\
	$(PS_SRCS)check_order.c\
	$(PS_SRCS)cleaner.c\
	$(PS_SRCS)sort_map.c\
	$(PS_SRCS)ft_is_slice.c\
	$(PS_SRCS)get_commands.c\
	$(PS_SRCS)insertion_sort.c\
	$(PS_SRCS)main_struct.c\
	$(PS_SRCS)middle_handler.c\
	$(PS_SRCS)optimize_way.c\
	$(PS_SRCS)ptr_to_a.c\
	$(PS_SRCS)ptr_to_top_b.c\
	$(PS_SRCS)set_steps.c\
	$(PS_SRCS)timsort.c\
	$(PS_SRCS)timsort_merge.c\
	$(PS_SRCS)vector.c\
	$(PS_SRCS)vector_arr.c\
	$(C_SRCS)stack_handler.c\
	$(C_SRCS)reader.c\
	$(C_SRCS)commander.c\
	$(C_SRCS)bigint_base.c\
	$(C_SRCS)spliter.c\
	$(C_SRCS)checker.c\
	$(PS_ROOT)main.c\

C_OBJ = $(C_SRC:%.c=%.o)
PS_OBJ = $(PS_SRC:%.c=%.o)

# flags-------------------------------------------------------------------------
FLAGS = -Wall -Werror -Wextra
I_FLAGS = -I $(PS_INC) -I $(P_INC) -I $(L_ROOT)

all: $(LIBFT) $(PRINTF) $(CHECKER) $(PUSH_SWAP)
# build external libraries------------------------------------------------------
$(LIBFT):
	$(MAKE) -C $(L_ROOT)
$(PRINTF):
	$(MAKE) -C $(P_ROOT)

# build checker-----------------------------------------------------------------
$(CHECKER): $(LIBFT) $(PRINTF) $(C_OBJ)
	gcc $(C_OBJ) -o $(CHECKER) $(I_FLAGS) $(FLAGS) $(L_FLAGS) $(P_FLAGS)
%.o: %.c $(PS_INC)push_swap.h
	gcc -c $< -o $@ $(I_FLAGS) $(FLAGS)

# build push swap---------------------------------------------------------------
$(PUSH_SWAP): $(LIBFT) $(PRINTF) $(PS_OBJ)
	gcc $(PS_OBJ) -o $(PUSH_SWAP) $(I_FLAGS) $(FLAGS) $(L_FLAGS) $(P_FLAGS)

# clean section-----------------------------------------------------------------
clean:
	$(MAKE) -C $(L_ROOT) clean
	$(MAKE) -C $(P_ROOT) clean
	rm -rf $(C_OBJ)
	rm -rf $(PS_OBJ)
fclean: clean
	$(MAKE) -C $(L_ROOT) fclean
	$(MAKE) -C $(P_ROOT) fclean
	rm -rf $(CHECKER)
	rm -rf $(PUSH_SWAP)
re: fclean all

.PHONY: all clean fclean re