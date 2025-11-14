/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:38:42 by babyf             #+#    #+#             */
/*   Updated: 2025/11/14 17:38:23 by babyf            ###   ########.fr       */
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


int	main(int ac, char **av)
{
	char *sel_str;

	sel_str = av[1];
	if (ac != 2 || read(STDIN_FILENO) || )
	{
		fprintf("Error: ");
		perror("");
		return (1);
	}
		
}