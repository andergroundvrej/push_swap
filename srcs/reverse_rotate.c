/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:40:44 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/10 03:36:37 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stacks, int *count)
{
	int	k;
	int	temp;

	if ((*stacks).a.size < 2)
		return ;
	k = (*stacks).a.size - 2;
	temp = (*stacks).a.content[(*stacks).a.size - 1];
	while (k >= 0)
	{
		(*stacks).a.content[k + 1] = (*stacks).a.content[k];
		k--;
	}
	(*stacks).a.content[0] = temp;
	if (write(1, "rra\n", 4) == -1)
		manage_error(stacks);
	++(*count);
}

void	rrb(t_stack *stacks, int *count)
{
	int	k;
	int	temp;

	if ((*stacks).b.size < 2)
		return ;
	k = (*stacks).b.size - 2;
	temp = (*stacks).b.content[(*stacks).b.size - 1];
	while (k >= 0)
	{
		(*stacks).b.content[k + 1] = (*stacks).b.content[k];
		k--;
	}
	(*stacks).b.content[0] = temp;
	if (write(1, "rrb\n", 4) == -1)
		manage_error(stacks);
	++(*count);
}

void	rrr(t_stack *stacks, int *count)
{
	int	k;
	int	temp;

	if ((*stacks).a.size < 2 || ((*stacks).b.size < 2))
		return ;
	k = (*stacks).a.size - 2;
	temp = (*stacks).a.content[(*stacks).a.size - 1];
	while (k >= 0)
	{
		(*stacks).a.content[k + 1] = (*stacks).a.content[k];
		k--;
	}
	(*stacks).a.content[0] = temp;
	k = (*stacks).b.size - 2;
	temp = (*stacks).b.content[(*stacks).b.size - 1];
	while (k >= 0)
	{
		(*stacks).b.content[k + 1] = (*stacks).b.content[k];
		k--;
	}
	(*stacks).b.content[0] = temp;
	if (write(1, "rrr\n", 4) == -1)
		manage_error(stacks);
	++(*count);
}
