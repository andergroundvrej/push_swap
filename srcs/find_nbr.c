/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:09:10 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/11 04:55:00 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(int *content, int size)
{
	int	i;
	int	k;

	i = 0;
	k = i + 1;
	while (k < size)
	{
		if (content[i] > content[k])
			i = k;
		k++;
	}
	return (content[i]);
}

int	biggest(int *content, int size)
{
	int	i;
	int	k;

	i = 0;
	k = i + 1;
	while (k < size)
	{
		if (content[i] < content[k])
			i = k;
		k++;
	}
	return (content[i]);
}

int	find_big(int *content, int size)
{
	int	i;
	int	k;

	i = 0;
	k = i + 1;
	while (k < size)
	{
		if (content[i] < content[k])
			i = k;
		k++;
	}
	return (i);
}

int	find_chunk(t_stack *stacks, double rank, int big_a)
{
	int	i;

	i = 0;
	while (i < stacks->a.size)
	{
		if (stacks->a.content[i] < stacks->b.size + rank
			&& (*stacks).a.content[i] < (big_a - 2))
			return (i);
		else
			i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
