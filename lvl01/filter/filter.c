/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:38:42 by babyf             #+#    #+#             */
/*   Updated: 2025/11/25 18:56:02 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Study the new functions and make a notion spreadsheet */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

# define BUFFER_SIZE 10000 + 1

void	ft_filter(char *buffer, const char *target)
{
	/* counters and a strlen for target */
	int	i, j, k;
	int	target_len;

	i = 0;
	target_len = strlen(target);
	/* start a while loop */
	while (buffer[i])
	{
		j = 0;
		while (target[j] && buffer [i + j] != '\0')
			j++;
		/* compare to the lenght of the target */
		if (j == target_len)
		{

		}
		/* init third counter */
		/* once the occurance is found [if]
			write * for occurence of arg s 
			increment 
		skip arg s */
		/* if occurance is not found [else]
			just write arg s
			increment */
	}
}

int	main(int ac, char **av)
{
	
}