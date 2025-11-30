/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:21:19 by babyf             #+#    #+#             */
/*   Updated: 2025/11/30 17:49:32 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 10
//cc broken_gnl.c -Wall -Wextra -Werror -D BUFFER_SIZE=3 -o gnl

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (!new)
		return (NULL);
	while (str[j])
	{
		new[j] = str[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	int			i;
	char		line[70000];
	static char	buff[BUFFER_SIZE];
	static int	buff_read;
	static int	buff_pos;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buff_pos >= buff_read)
		{
			buff_read = read(fd, buff, BUFFER_SIZE);
			buff_pos = 0;
			if (buff_read <= 0)
				break ;
		}
		line[i++] = buff[buff_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

/*
int main()
{
	int fd = open("test", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}
*/