/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:30:19 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/11 06:07:40 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *stacks)
{
	int	k;
	int	temp;

	if ((*stacks).a.size < 2)
		return ;
	k = 0;
	temp = (*stacks).a.content[0];
	while (k < (*stacks).a.size - 1)
	{
		(*stacks).a.content[k] = (*stacks).a.content[k + 1];
		k++;
	}
	(*stacks).a.content[(*stacks).a.size - 1] = temp;
}

void	rb(t_stack *stacks)
{
	int	k;
	int	temp;

	if ((*stacks).b.size < 2)
		return ;
	k = 0;
	temp = (*stacks).b.content[0];
	while (k < (*stacks).b.size - 1)
	{
		(*stacks).b.content[k] = (*stacks).b.content[k + 1];
		k++;
	}
	(*stacks).b.content[(*stacks).b.size - 1] = temp;
}

void	rr(t_stack *stacks)
{
	if ((*stacks).a.size < 2 && ((*stacks).b.size < 2))
		return ;
	if ((*stacks).a.size < 2)
	{
		rb(stacks);
		return ;
	}
	if ((*stacks).b.size < 2)
	{
		ra(stacks);
		return ;
	}
	ra(stacks);
	rb(stacks);
}
