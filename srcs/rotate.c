/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:30:19 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/10 03:34:52 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stacks, int *count)
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
	if (write(1, "ra\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}

void	rb(t_stack *stacks, int *count)
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
	if (write(1, "rb\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}

void	rr(t_stack *stacks, int *count)
{
	int	k;
	int	temp;

	if ((*stacks).a.size < 2 || ((*stacks).b.size < 2))
		return ;
	k = 0;
	temp = (*stacks).a.content[0];
	while (k < (*stacks).a.size - 1)
	{
		(*stacks).a.content[k] = (*stacks).a.content[k + 1];
		k++;
	}
	(*stacks).a.content[(*stacks).a.size - 1] = temp;
	k = 0;
	temp = (*stacks).b.content[0];
	while (k < (*stacks).b.size - 1)
	{
		(*stacks).b.content[k] = (*stacks).b.content[k + 1];
		k++;
	}
	(*stacks).b.content[(*stacks).b.size - 1] = temp;
	if (write(1, "rr\n", 3) == -1)
		manage_error(stacks);
	++(*count);
}
