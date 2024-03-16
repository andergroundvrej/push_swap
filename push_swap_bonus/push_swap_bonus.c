/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:10:20 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/11 05:21:17 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"

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
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

void	swap(t_stack *stacks, int ac)
{
	char	*line;

	(*stacks).a.size = ac - 1;
	(*stacks).b.size = 0;
	line = get_next_line(0);
	while (line)
	{
		apply_swap(line, stacks);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (stacks->b.size > 0)
	{
		ft_putstr_fd("KO\n", 1, *stacks);
		free_stacks(*stacks);
		exit(0);
	}
	if (end(stacks) == 0)
		ft_putstr_fd("OK\n", 1, *stacks);
	else
		ft_putstr_fd("KO\n", 1, *stacks);
}

int	apply_swap(char *line, t_stack *stacks)
{
	int	rotate;

	rotate = apply_rotate(line, stacks);
	if (rotate == 0)
		return (0);
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stacks);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stacks);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stacks);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stacks);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stacks);
	else
	{
		free(line);
		free_stacks(*stacks);
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (0);
}

int	apply_rotate(char *line, t_stack *stacks)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(stacks);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stacks);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stacks);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stacks);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stacks);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stacks);
	else
		return (1);
	return (0);
}
