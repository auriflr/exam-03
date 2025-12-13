/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afloris <afloris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:21:19 by babyf             #+#    #+#             */
/*   Updated: 2025/12/13 10:57:35 by afloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	new = (char *)malloc(i + 1);
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
	static char	buff[BUFFER_SIZE];
	static int	buff_read;
	static int	buff_pos;
	char		line[70000];

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
				break;
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
int	main()
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
}
*/

