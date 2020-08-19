#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include <limits.h>

# define BIGINT_SIZE	10
# define VECTOR_SIZE	256u

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
	void			*arr;
	size_t			size;
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
	int				beg;
	int				end;
	int				*begin;
	int				*size;
}					t_map;

typedef struct		bigint
{
	int				bigint[BIGINT_SIZE];
	int				length;
	int				sign;
}					t_bigint;

t_stack				*read_argv(int argc, char **argv);
t_bigint			initialize_big(t_bigint *elephant);
int					set_len_big(t_bigint *elephant);

void				run_command(char *command, t_stack **a, t_stack **b);

int					check_asc_order(t_stack *a, t_stack *b);
int					check_dsc_order(t_stack *a);
int					ft_isslice(t_stack *a);

t_stack				*create_elem(void);
void				push_in_stack(t_stack **stack, t_stack *next);

int					check(int argc, char **argv);//del
t_vectors			*get_commands(t_stack **a, t_stack **b);
int					*timsort(int *arr, int size);
int					*merge(int *arr, t_map **map);
int					*insertion_sort(int *arr, t_map *map);


t_vectors			*create_vectors(size_t size);
int					push_in_vector(t_vector **v, int value, size_t size);

void				clean_and_exit(t_stack **a, t_stack **b, t_vectors **v,\
					char option);
void				destroy_map(t_map **map);

void				all_to_b(t_stack **a, t_stack **b, t_vectors **info);
int					check_mid(t_stack *a, int middle);
int					get_middle(t_stack **a);

void				print_info(t_vectors *info);//del
void				check_ord(int *arr, int size);//del
void				print_arr(int *arr, int size);//del
void				print_stacks(t_stack *a, t_stack *b);//del

#endif
