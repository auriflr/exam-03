/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:38:42 by babyf             #+#    #+#             */
/*   Updated: 2025/11/28 17:10:08 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* read() function moves bytes from a file descriptor into memory 
BUFFER is a memory allocation (a reserved space for memory where i place the input str)
realloc() changes the size of the allocation pointer to by ptr to size and return ptr. 
If there's not enough room for the allocation, it creates a new allocation and copies as
much of the old data pointer to by ptr as will fit the new allocation, and then 
frees the old allocation, returning a pointer to the allocated memory. */

/* Study the new functions and make a notion spreadsheet */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

# define BUFFER_SIZE 10000 + 1

/* think of buffer like an input str*/
void	ft_filter(char *buffer, const char *target)
{
	int		i;
	int		j, k;
	int		target_len;

	target_len = strlen(target);
	i = 0;
	while (buffer[i])
	{
		j = 0;
		/* check for occurence at the current position */
		while (target[j] && buffer[i + j] == target[j])
			j++;
		if (j == target_len)
		{
			/* now i need to write the asterisk*/
			k = 0;
			while (k < target_len)
			{
				write (1, "*", 1);
				k++;
			}
			i += target_len;
		}
		else
		{
			write (1, &buffer[i], 1);
			i++;
		}
			
	}
}

int	main(int ac, char **av)
{
	char	tmp[BUFFER_SIZE];
	char	*result; 
	char	*buffer; /* aka input str */
	int		total;
	ssize_t	bytes;

	result = NULL;
	total = 0;
	if (ac != 2 || av[1][0] == '\0')
		return (1);
	while ((bytes = read(0, tmp, BUFFER_SIZE)) > 0)
	{
		/* now with realloc () i need to expand the memory of 
		the buffer to accomodate the new characters*/
		buffer = realloc (result, total + bytes + 1);
		if (!buffer)
		{
			free(result);
			perror("realloc");
			return (1);
		}
		result = buffer;
		memmove(result + total, tmp, bytes);
		total += bytes;
		result[total] = '\0';
	}
	/* now for some error handling */
	if (bytes < 0)
	{
		perror ("read");
		free (result);
		return (1);
	}
	if (!result)
		return (0);
	ft_filter (result, av[1]);
	free (result);
	return (0);
}