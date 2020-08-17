#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include <limits.h>

# define BIGINT_SIZE	10
# define VECTOR_SIZE	150u
# define RB		0b00000001u
# define SA		0b00000010u
# define SB		0b00000100u
# define RRA	0b00001000u
# define RRB	0b00010000u
# define PA		0b00100000u
# define PB		0b01000000u
# define RA		0b10000000u

typedef struct		s_vector
{
	size_t			size;
	void			*arr;
	int				cur;
}					t_vector;

typedef struct		s_vectors
{
	t_vector		*cmd;
	t_vector		*chunk;
}					t_vectors;

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

void				print(t_stack *a, t_stack *b);
int					check(int argc, char **argv);
t_vectors			*get_commands(t_stack **a, t_stack **b, int argc);
int					*timsort(int *arr, int size);
void				print_arr(int *arr, int size);
int					check_order(t_stack *a, t_stack *b);

t_vectors			*create_vectors(size_t size);
int					push_in_vector(t_vector **v, int value, size_t size);

void				clean_and_exit(t_stack **a, t_stack **b, t_vectors **v,\
					char option);
void				destroy_stack(t_stack **stack);
void				destroy_vectors(t_vectors **v);

#endif
