/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:18:33 by ahakobia          #+#    #+#             */
/*   Updated: 2024/03/17 16:58:22 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(char **av, t_stack stacks)
{
	int	j;
	int	len;

	j = 1;
	while (av[j])
	{
		len = ft_strlen(av[j]);
		if (ft_atoi(av[j]) > 2147483647 || ft_atoi(av[j]) < -2147483648
			|| len > 63)
		{
			ft_putstr_fd("Error\n", 2, stacks);
			free_stacks(stacks);
			exit(-1);
		}
		if ((len == 1 && !ft_isdigit(ft_atoi(av[j]))) || (len == 0))
		{
			ft_putstr_fd("Error\n", 2, stacks);
			free_stacks(stacks);
			exit(-1);
		}
		j++;
	}
}

void	check_double_and_fill(char **av, int ac, t_stack stacks)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 1;
	while (j < ac)
	{
		i = j + 1;
		while (i < ac)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
			{
				ft_putstr_fd("Error\n", 2, stacks);
				free_stacks(stacks);
				exit(-1);
			}
			else
				i++;
		}
		stacks.a.content[k] = ft_atoi(av[j]);
		k++;
		j++;
	}
}

void	free_stacks(t_stack stacks)
{
	free(stacks.a.content);
	free(stacks.b.content);
}

int	main(int ac, char **av)
{
	int		count;
	t_stack	stacks;

	if (ac < 2)
		return (0);
	stacks.a.content = malloc(sizeof(int) * (ac - 1));
	stacks.b.content = malloc(sizeof(int) * (ac - 1));
	if (!stacks.b.content || !stacks.a.content)
	{
		free_stacks(stacks);
		return (0);
	}
	count = 0;
	parse(av, stacks);
	check_double_and_fill(av, ac, stacks);
	swap(&stacks, ac, &count);
	free_stacks(stacks);
	return (count);
}
