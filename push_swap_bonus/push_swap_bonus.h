/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:11:14 by ahakobia          #+#    #+#             */
/*   Updated: 2024/03/15 18:36:49 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "unistd.h"
# include <stdlib.h>

typedef struct s_value
{
	int		*content;
	int		size;
}			t_value;

typedef struct s_stack
{
	t_value		a;
	t_value		b;
}				t_stack;

int				apply_rotate(char *line, t_stack *stacks);
void			ranking_stack(t_stack *stacks);
int				ft_strcmp(char *s1, char *s2);
void			ft_putstr_fd(char *s, int fd, t_stack stacks);
void			parse(char **av, t_stack stacks);
void			check_double_and_fill(char **av, int ac, t_stack stacks);
long long		ft_atoi(const char *nptr);
int				ft_strlen(char const *s);
int				ft_isdigit(int c);
void			swap(t_stack *stacks, int size);
void			three_nbr(t_stack *stacks);
int				end(t_stack *stacks);
void			three_nbr_2(t_stack *stacks);
void			rra(t_stack *stacks);
void			rrb(t_stack *stacks);
void			rrr(t_stack *stacks);
void			ra(t_stack *stacks);
void			rb(t_stack *stacks);
void			rr(t_stack *stacks);
void			pb(t_stack *stacks);
void			pa(t_stack *stacks);
void			ss(t_stack *stacks);
void			sb(t_stack *stacks);
void			sa(t_stack *stacks);
int				smallest(int *content, int size);
int				biggest(int *content, int size);
int				find_big(int *content, int size);
void			free_stacks(t_stack stacks);
int				rank_nbr(t_stack *stacks, int i);
void			*ft_memcpy(void *dest, const void *src, int n);
int				ft_pow(double a);
int				find_chunk(t_stack *stacks, double rank, int big_a);
void			pre_sort(t_stack *stacks, int big_a);
void			final_sort(t_stack *stacks, int big_a);
void			process_remaining(t_stack *stacks, int bigger,
					int big_a);
void			process_high_big_b(t_stack *stacks, int bigger,
					int big_a);
void			process_low_big_b(t_stack *stacks, int *big_b,
					int big_a);
int				apply_swap(char *line, t_stack *stacks);

#endif
