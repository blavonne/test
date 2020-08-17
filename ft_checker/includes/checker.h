#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include <limits.h>

# define BIGINT_SIZE	10

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_map
{
	int				*begin;
	int				*size;
}					t_map;

typedef struct		bigint
{
	int				bigint[BIGINT_SIZE];
	int				length;
	int				sign;
}					t_bigint;

void				put_errmsg_and_exit(char type);
t_stack				*read_argv(int argc, char **argv);

t_bigint			initialize_big(t_bigint *elephant);
int					set_len_big(t_bigint *elephant);

void				run_command(char *command, t_stack **a, t_stack **b);

t_stack				*create_elem(void);
void				push_in_stack(t_stack **stack, t_stack *next);
void				destroy_stack(t_stack **stack);
void				clean_exit(t_stack **stack, char type);

void				print(t_stack *a, t_stack *b);
int					check(int argc, char **argv);
char				**get_commands(t_stack **a, t_stack **b, int argc);
int					*timsort(int *arr, int size);
void				print_arr(int *arr, int size);
void				check_ord(int *arr, int size);

#endif
