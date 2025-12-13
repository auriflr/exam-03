/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:11:19 by babyf             #+#    #+#             */
/*   Updated: 2025/12/13 10:56:18 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void	filter(char *buff, char *target)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		j = 0;
		while (target[j] && buff[i + j] && buff[i + j] == target[j])
			j++;
		if (target[j] == '\0')
		{
			while (j-- > 0)
				write (1, "*", 1);
			i += strlen(target);
		}
		else
		{
			write (1, &buff[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || av[1][0] == '\0')
		return (1);
	char	c;
	char	*buff;
	int		size;
	int		check;
	
	buff = calloc(1, sizeof(char) * 1);
	size = 0;
	while ((check = read(0, &c, 1)) > 0)
	{
		buff = realloc (buff, size + 2);
		if (!buff)
		{
			free (buff);
			return (1);
		}
		buff[size] = c;
		size++;
		buff[size] = '\0';
	}
	filter(buff, av[1]);
	free (buff);
}
