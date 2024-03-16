/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakobia <ahakobia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:57:12 by ahakobia          #+#    #+#             */
/*   Updated: 2024/02/14 13:01:45 by ahakobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	n;
	int			k;

	k = 0;
	i = 0;
	n = 0;
	if (ft_strcmp((char *)nptr, "-2147483648") == 0)
		return (-2147483648);
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			k = 1;
	}
	if (nptr[i] == '\0')
		return (2147483648);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		n = n * 10 + nptr[i++] - '0';
	if (nptr[i] != '\0' || n > 2147483647 || n < -2147483648)
		return (2147483648);
	if (k == 1)
		n *= -1;
	return (n);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd, t_stack stacks)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (write(fd, s, i) == -1)
	{
		free_stacks(stacks);
		write(2, "Error\n", 6);
		exit(-1);
	}
}

int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 9)
		return (1);
	else
		return (0);
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
