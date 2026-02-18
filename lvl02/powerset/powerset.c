/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:46:35 by babyf             #+#    #+#             */
/*   Updated: 2026/02/18 16:21:34 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"

void	parse_set(int *set, char **av, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
}

/* mask is a single set */
int	ft_sum(int *set, int size, int mask)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		if (mask & (1 << i))
			sum += set[i];
		i++;
	}
	return (sum);
}

void	print_subset(int *set, int size, int mask)
{
	int	i;
	int	first = 1;

	for (i = 0; i < size; i++)
	{
		if (mask & (1 << i))
		{
			if (first)
			{
				printf("%d", set[i]);
				first = 0;
			}
			else
				printf(" %d", set[i]);
		}
	}
	printf("\n");
}


void	ft_sumcheck(int *set, int size, int target)
{
	int	tot_subset;
	int	mask;
	int	sum;

	tot_subset = 1 << size;
	mask = 0;
	while (mask < tot_subset)
	{
		sum = ft_sum(set, size, mask);
		if (sum == target)
			print_subset(set, size, mask);
		mask++;
	}
}

int	main(int ac, char **av)
{
	int	n;
	int	size;

	if (ac < 3)
		return (0);
	n = atoi(av[1]);
	size = ac - 2;
	int set[size];
	parse_set(set, av, size);
	ft_sumcheck(set, size, n);
	return (1);
}