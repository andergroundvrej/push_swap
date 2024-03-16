/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:17:20 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/09 04:15:15 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_low_big_b(t_stack *stacks, int *big_b, int big_a, int *count)
{
	int	bigger;

	bigger = biggest((*stacks).b.content, (*stacks).b.size);
	while (*big_b != 0)
	{
		if ((*stacks).a.content[(*stacks).a.size - 1] == big_a
			|| (*stacks).b.content[0]
			> (*stacks).a.content[(*stacks).a.size - 1])
		{
			if ((*stacks).a.content[(*stacks).a.size - 1] > bigger
				&& (*stacks).a.content[(*stacks).a.size - 1] != big_a)
				rra(stacks, count);
			pa(stacks, count);
			if (biggest((*stacks).b.content, (*stacks).b.size)
				> (*stacks).a.content[0])
				ra(stacks, count);
		}
		if ((*stacks).a.content[(*stacks).a.size - 1] > bigger)
			rra(stacks, count);
		if (bigger != (*stacks).b.content[0])
			rb(stacks, count);
		(*big_b)--;
	}
}

void	process_high_big_b(t_stack *stacks, int bigger, int big_a, int *count)
{
	while (bigger != (*stacks).b.content[0])
	{
		if ((*stacks).a.content[(*stacks).a.size - 1] == big_a
			|| (*stacks).b.content[0]
			> (*stacks).a.content[(*stacks).a.size - 1])
		{
			if ((*stacks).a.content[(*stacks).a.size - 1] > bigger
				&& (*stacks).a.content[(*stacks).a.size - 1] != big_a)
				rra(stacks, count);
			pa(stacks, count);
			if (biggest((*stacks).b.content, (*stacks).b.size)
				> (*stacks).a.content[0])
				ra(stacks, count);
		}
		if (((*stacks).a.content[(*stacks).a.size - 1] > bigger
				&& (*stacks).a.content[(*stacks).a.size - 1] != big_a)
			&& (bigger != (*stacks).b.content[0]))
			rrr(stacks, count);
		else if ((*stacks).a.content[(*stacks).a.size - 1] > bigger
			&& (*stacks).a.content[(*stacks).a.size - 1] != big_a)
			rra(stacks, count);
		else if (bigger != (*stacks).b.content[0])
			rrb(stacks, count);
	}
}

void	process_remaining(t_stack *stacks, int bigger, int big_a, int *count)
{
	while ((*stacks).a.content[(*stacks).a.size - 1] > bigger
		&& (*stacks).a.content[(*stacks).a.size - 1] != big_a)
		rra(stacks, count);
	if ((*stacks).b.content[0] == bigger)
		pa(stacks, count);
}

void	final_sort(t_stack *stacks, int big_a, int *count)
{
	int	big_b;
	int	bigger;

	while ((*stacks).b.size > 0)
	{
		bigger = biggest((*stacks).b.content, (*stacks).b.size);
		big_b = find_big((*stacks).b.content, (*stacks).b.size);
		if (big_b < (*stacks).b.size / 2)
			process_low_big_b(stacks, &big_b, big_a, count);
		else
			process_high_big_b(stacks, bigger, big_a, count);
		process_remaining(stacks, bigger, big_a, count);
	}
	if ((*stacks).a.content[0] > (*stacks).a.content[1])
		sa(stacks, count);
	if ((*stacks).a.content[(*stacks).a.size - 1]
		== smallest((*stacks).a.content, (*stacks).a.size))
		rra(stacks, count);
	while ((*stacks).a.content[(*stacks).a.size - 1] != big_a)
		rra(stacks, count);
}
