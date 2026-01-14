/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:18:57 by babyf             #+#    #+#             */
/*   Updated: 2026/01/14 17:31:19 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

void	swap(char *x, char *y)
{
	char	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_permutation(char *str, int start, int end)
{
	int	i;

	if (start == end)
		put_str(str);
	else
	{
		i = start;
		while (i <= end)
		{
			swap((str + start), (str + i));
			ft_permutation(str, start + 1, end);
			swap((str + start), (str + i));
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (-1);

	int	n;

	n = ft_strlen(av[1]);
	ft_permutation(av[1], 0, n-1);
	return (0);
}