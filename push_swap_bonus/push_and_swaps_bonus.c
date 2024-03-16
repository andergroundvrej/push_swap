/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swaps_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:33:13 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/14 14:34:35 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *stacks)
{
	int	temp;

	if ((*stacks).a.size < 2)
		return ;
	temp = (*stacks).a.content[0];
	(*stacks).a.content[0] = (*stacks).a.content[1];
	(*stacks).a.content[1] = temp;
}

void	sb(t_stack *stacks)
{
	int	temp;

	if ((*stacks).b.size < 2)
		return ;
	temp = (*stacks).b.content[0];
	(*stacks).b.content[0] = (*stacks).b.content[1];
	(*stacks).b.content[1] = temp;
}

void	ss(t_stack *stacks)
{
	if ((*stacks).a.size < 2 && ((*stacks).b.size < 2))
		return ;
	if ((*stacks).a.size < 2)
	{
		sb(stacks);
		return ;
	}
	if ((*stacks).b.size < 2)
	{
		sa(stacks);
		return ;
	}
	sa(stacks);
	sb(stacks);
}

void	pa(t_stack *stacks)
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
}

void	pb(t_stack *stacks)
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
}
