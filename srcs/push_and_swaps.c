/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:33:13 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/10 03:36:16 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stacks, int *count)
{
	int	temp;

	if ((*stacks).a.size < 2)
		return ;
	temp = (*stacks).a.content[0];
	(*stacks).a.content[0] = (*stacks).a.content[1];
	(*stacks).a.content[1] = temp;
	if (write(1, "sa\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}

void	sb(t_stack *stacks, int *count)
{
	int	temp;

	if ((*stacks).b.size < 2)
		return ;
	temp = (*stacks).b.content[0];
	(*stacks).b.content[0] = (*stacks).b.content[1];
	(*stacks).b.content[1] = temp;
	if (write(1, "sb\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}

void	ss(t_stack *stacks, int *count)
{
	int	temp;

	if ((*stacks).a.size < 2 || ((*stacks).b.size < 2))
		return ;
	temp = (*stacks).a.content[0];
	(*stacks).a.content[0] = (*stacks).a.content[1];
	(*stacks).a.content[1] = temp;
	temp = (*stacks).b.content[0];
	(*stacks).b.content[0] = (*stacks).b.content[1];
	(*stacks).b.content[1] = temp;
	if (write(1, "ss\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}

void	pa(t_stack *stacks, int *count)
{
	int	k;
	int	j;

	if ((*stacks).b.size == 0)
		return ;
	(*stacks).a.size++;
	k = (*stacks).a.size - 2;
	j = 0;
	while (k >= 0)
	{
		(*stacks).a.content[k + 1] = (*stacks).a.content[k];
		k--;
	}
	(*stacks).a.content[0] = (*stacks).b.content[0];
	while (j < (*stacks).b.size - 1)
	{
		(*stacks).b.content[j] = (*stacks).b.content[j + 1];
		j++;
	}
	(*stacks).b.size--;
	if (write(1, "pa\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}

void	pb(t_stack *stacks, int *count)
{
	int	k;
	int	j;

	if ((*stacks).a.size == 0)
		return ;
	(*stacks).b.size++;
	k = (*stacks).b.size - 2;
	j = 0;
	while (k >= 0)
	{
		(*stacks).b.content[k + 1] = (*stacks).b.content[k];
		k--;
	}
	(*stacks).b.content[0] = (*stacks).a.content[0];
	while (j < (*stacks).a.size - 1)
	{
		(*stacks).a.content[j] = (*stacks).a.content[j + 1];
		j++;
	}
	(*stacks).a.size--;
	if (write(1, "pb\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}
