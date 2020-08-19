#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include <limits.h>

# define BIGINT_SIZE	10
# define V_SIZE			256u
# define VARR_SIZE		30u

# define RA		0b00000001u
# define RB		0b00000010u
# define RR		0b00000011u
# define SA		0b00000100u
# define SB		0b00001000u
# define SS		0b00001100u
# define RRA	0b00010000u
# define RRB	0b00100000u
# define RRR	0b00110000u
# define PB		0b01000000u
# define PA		0b10000000u


typedef struct		s_vector
{
	void			*arr;
	size_t			size;
	int				next;
}					t_vector;

typedef struct		s_main
{
	t_vector		*cmd_c;
	t_vector		*count_steps_i;
	t_vector		**cmd_arr;
	int				arr_size;
}					t_main;

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

t_stack				*create_stack(void);
void				push_in_stack(t_stack **stack, t_stack *next);

int					check(int argc, char **argv);//del
t_main				*get_commands(t_stack **a, t_stack **b);
int					*timsort(int *arr, int size);
int					*merge(int *arr, t_map **map);
int					*insertion_sort(int *arr, t_map *map);


t_main				*create_main_struct(void);
void				destroy_main(t_main **m);
t_vector			*create_vector(void);
int					push_in_vector(t_vector **v, int value, size_t size);
t_vector			**create_varr(void);
int					push_in_varr(t_main **m, t_vector *tmp);

void				clean_and_exit(t_stack **a, t_stack **b, t_main **m,\
					char option);
void				destroy_map(t_map **map);

void				all_to_b(t_stack **a, t_stack **b, t_main **info);
int					check_mid(t_stack *a, int middle);
int					get_middle(t_stack **a);
void				all_to_a(t_stack **a, t_stack **b, t_main **info);

void				print_info(t_main *info);//del
void				check_ord(int *arr, int size);//del
void				print_arr(int *arr, int size);//del
void				print_stacks(t_stack *a, t_stack *b);//del


#endif
