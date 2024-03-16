/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:40:44 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/11 06:04:03 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *stacks)
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
}

void	rrb(t_stack *stacks)
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
}

void	rrr(t_stack *stacks)
{
	if ((*stacks).a.size < 2 && ((*stacks).b.size < 2))
		return ;
	if ((*stacks).a.size < 2)
	{
		rrb(stacks);
		return ;
	}
	if ((*stacks).b.size < 2)
	{
		rra(stacks);
		return ;
	}
	rra(stacks);
	rrb(stacks);
}
