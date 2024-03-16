/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:10:20 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/09 04:15:27 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end(t_stack *stacks)
{
	int	i;
	int	k;

	i = 0;
	while (i < (*stacks).a.size - 1)
	{
		k = i + 1;
		while (k < (*stacks).a.size)
		{
			if ((*stacks).a.content[i] > (*stacks).a.content[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	three_nbr(t_stack *stacks, int *count)
{
	if ((*stacks).a.content[0] > (*stacks).a.content[1]
		&& (*stacks).a.content[0] > (*stacks).a.content[2]
		&& (*stacks).a.content[1] > (*stacks).a.content[2])
	{
		sa(stacks, count);
		rra(stacks, count);
	}
	if ((*stacks).a.content[0] < (*stacks).a.content[1]
		&& (*stacks).a.content[0] < (*stacks).a.content[2]
		&& (*stacks).a.content[1] > (*stacks).a.content[2])
	{
		sa(stacks, count);
		ra(stacks, count);
	}
	if ((*stacks).a.content[0] > (*stacks).a.content[1]
		&& (*stacks).a.content[1] < (*stacks).a.content[2]
		&& (*stacks).a.content[0] > (*stacks).a.content[2])
		ra(stacks, count);
	three_nbr_2(stacks, count);
}

void	three_nbr_2(t_stack *stacks, int *count)
{
	if ((*stacks).a.content[0] < (*stacks).a.content[1]
		&& (*stacks).a.content[0] > (*stacks).a.content[2]
		&& (*stacks).a.content[1] > (*stacks).a.content[2])
		rra(stacks, count);
	if ((*stacks).a.content[0] > (*stacks).a.content[1]
		&& (*stacks).a.content[0] < (*stacks).a.content[2]
		&& (*stacks).a.content[1] < (*stacks).a.content[2])
		sa(stacks, count);
}

void	swap(t_stack *stacks, int ac, int *count)
{
	int	big_a;

	(*stacks).a.size = ac - 1;
	(*stacks).b.size = 0;
	ranking_stack(stacks);
	big_a = biggest((*stacks).a.content, (*stacks).a.size);
	if (end(stacks) != 1)
	{
		pre_sort(stacks, big_a, count);
		final_sort(stacks, big_a, count);
	}
}

void	pre_sort(t_stack *stacks, int big_a, int *count)
{
	double	rank;

	rank = ft_pow(0.000000053 * (*stacks).a.size) + 0.03
		* (*stacks).a.size + 14.5;
	while ((*stacks).a.size > 3)
	{
		if ((*stacks).a.content[0] < (*stacks).b.size
			&& (*stacks).a.content[0] < (big_a - 2))
			pb(stacks, count);
		else if ((*stacks).a.content[0] < (*stacks).b.size + rank
			&& (*stacks).a.content[0] < (big_a - 2))
		{
			pb(stacks, count);
			rb(stacks, count);
		}
		else
		{
			if (find_chunk(stacks, rank, big_a) > (stacks->a.size / 2))
				rra(stacks, count);
			else
				ra(stacks, count);
		}
	}
	three_nbr(stacks, count);
}
