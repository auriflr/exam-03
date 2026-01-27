/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brief_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:57:55 by babyf             #+#    #+#             */
/*   Updated: 2026/01/27 17:05:16 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_strdup(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	if (str[i])
		i++;
	new = (char *) malloc (i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (str[j])
	{
		new[j] = str[j];
		j++;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	static int	buff_read;
	static int	buff_pos;
	int			i;
	char		line[70000];

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buff_pos >= buff_read)
		{
			buff_read = read (fd, buff, BUFFER_SIZE);
			buff_pos = 0;
			if (buff_read <= 0)
				break ;
		}
		line[i++] = buff[buff_pos++];
        if (line[i - 1] == '\n')
            break;
	}
	line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}

int	main(void)
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