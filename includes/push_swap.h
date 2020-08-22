/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:42:34 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:42:36 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "printf.h"
# include <limits.h>

# define BIGINT_SIZE	10
# define V_SIZE			200u
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
	size_t			next;
}					t_vector;

typedef struct		s_main
{
	t_vector		*cmd_c;
	t_vector		*count_steps_i;
	t_vector		**cmd_arr;
	size_t			arr_size;
	size_t			arr_next;
}					t_info;

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

typedef struct		s_bigint
{
	int				bigint[BIGINT_SIZE];
	int				length;
	int				sign;
}					t_bigint;

t_stack				*read_argv(int argc, char **argv);
t_bigint			initialize_big(t_bigint *elephant);
int					set_len_big(t_bigint *elephant);
t_stack				*create_stack(void);
t_stack				*copy_stack(t_stack *src);
int					push_in_stack(t_stack **stack, int value);
int					get_number(char *str, t_stack **stack);
int					try_to_split(char *str, t_stack **stack);

void				run_command(char *command, t_stack **a, t_stack **b);
int					check_command(char *cmd);

int					check_asc_order(t_stack *a, t_stack *b);
int					ft_isslice(t_stack *a);

t_info				*create_main_struct(void);
t_vector			*create_vector(void);
t_vector			*copy_vector(t_vector *src);
int					push_in_vector(t_vector **v, int value, size_t size);
t_vector			**create_varr(void);
int					push_in_varr(t_info **m, t_vector *tmp);

void				clean_and_exit(t_stack **a, t_stack **b, t_info **m,\
					char option);
void				destroy_map(t_map **map);
void				destroy_main(t_info **m);
void				destroy_vector(t_vector **v);
void				destroy_stack(t_stack **stack);
void				destroy_varr(t_info **m);

void				all_to_b(t_stack **a, t_stack **b, t_info **info);
int					check_mid(t_stack *a, int middle);
int					get_middle(t_stack **a);
t_info				*get_commands(t_stack **a, t_stack **b);
int					*timsort(int *arr, int size);
t_map				*set_map(t_map *map, int i);
int					*merge(int *arr, t_map **map);
int					*insertion_sort(int *arr, t_map *map);
void				all_to_a(t_stack **a, t_stack **b, t_info **m);
t_vector			*ptr_to_top_b(t_stack *b, t_stack *ptr);
int					ptr_to_a(t_stack *a, t_stack *ptr, t_vector **way);
int					set_steps(t_stack *a, t_stack *b, t_stack *ptr, t_info **m);
int					cat_vectors(t_vector **dest, t_vector *src);
void				optimize_way(t_vector *way);

void				print_info(t_info *info);

#endif
