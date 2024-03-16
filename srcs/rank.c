/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:16:52 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/06 18:48:16 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_nbr(t_stack *stacks, int i)
{
	int	rank;
	int	k;

	k = 0;
	rank = 0;
	while (k < stacks->a.size)
	{
		if (stacks->a.content[i] > stacks->a.content[k])
			rank++;
		k++;
	}
	return (rank);
}

void	ranking_stack(t_stack *stacks)
{
	int	i;
	int	*new_tab;

	i = 0;
	new_tab = malloc(sizeof(int) * stacks->a.size);
	if (!new_tab)
	{
		free_stacks(*stacks);
		exit(-1);
	}
	while (i < stacks->a.size)
	{
		new_tab[i] = rank_nbr(stacks, i);
		i++;
	}
	i = 0;
	while (i < stacks->a.size)
	{
		stacks->a.content[i] = new_tab[i];
		i++;
	}
	free(new_tab);
}

int	ft_pow(double a)
{
	return (a * a);
}
