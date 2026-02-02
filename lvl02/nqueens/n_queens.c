/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:44:41 by babyf             #+#    #+#             */
/*   Updated: 2026/02/02 17:34:29 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "n_queens.h"

void	put_array(int board[], int n)
{
	int		i;
	char	c;
	i = 0;
	while (i < n)
	{
		c = board[i] + '0';
		write (1, &c, 1);
		write (1, " ", 1);
		i++;
	}
	write (1, "\n", 1);
}

int	is_safe(int board[], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || (i - row) == (board[i] - col) || (i - row) == (col - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtrack(int board[], int row, int n, int *count)
{
	int	col;

	col = 0;
	if (row == n)
	{
		put_array(board, n);
		(*count)++;
		return ;
	}
	while (col < n)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			ft_backtrack(board, row + 1, n, count);
		}
		col++;
	}
}

void	ft_solve(int n)
{
	int	board[n];
	int	count;

	count = 0;
	ft_backtrack(board, 0, n, &count);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac != 2)
		return (-1);
	n = atoi(av[1]);
	ft_solve(n);
	return(0);
}