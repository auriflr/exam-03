/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:46:53 by babyf             #+#    #+#             */
/*   Updated: 2026/02/02 17:35:54 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rip.h"

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

int	rem_inv(char *str)
{
	int	i;
	int	open;
	int	closed;

	i = 0;
	open = 0;
	closed = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				closed++;
		}
		i++;
	}
	return (open + closed);
}

void rip(char *str, int len, int i, int balance, int matched, int removed)
{
    if (i == len)
    {
        if (balance == 0 && matched == removed)
            puts(str);
        return;
    }
    if (str[i] == '(')
    {
        rip(str, len, i + 1, balance + 1, matched, removed);
        if (matched < removed)
        {
            str[i] = ' ';
            rip(str, len, i + 1, balance, matched + 1, removed);
            str[i] = '(';
        }
    }
    else if (str[i] == ')')
    {
        if (balance > 0)
            rip(str, len, i + 1, balance - 1, matched, removed);
        if (matched < removed)
        {
            str[i] = ' ';
            rip(str, len, i + 1, balance, matched + 1, removed);
            str[i] = ')';
        }
    }
}


int	main(int ac, char **av)
{
	char	*tmp;
	int		len;
	int		i;
	int		inv;

	if (ac != 2 || !av[1] || av[1][0] == '\0')
			return (0);
	i = 0;
	len = ft_strlen(av[1]);
	tmp = av[len + 1];
	inv = 0;
	while (i < len)
	{
		tmp[i] = av[1][i];
		i++;
	}
	tmp[i] = '\0';
	inv = rem_inv(tmp);
	rip (tmp, len, 0, 0, 0, inv);
}