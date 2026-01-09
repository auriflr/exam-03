/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:21:19 by babyf             #+#    #+#             */
/*   Updated: 2026/01/09 15:57:09 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* recreations */
int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchcpy(char *dst, char *src, char c)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == c)
		dst[i++] = c;
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*res;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	res = (char *) malloc (sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	ft_strchcpy(res, str, '\0');
	return (res);
}

char	*ft_strjoin(char *start, char *end)
{
	int		size1;
	int		size2;
	int		i;
	char	*joined;

	if (!start || !end)
		return (NULL);
	i = 0;
	size1 = ft_strlen(start);
	size2 = ft_strlen(end);
	joined = (char *) malloc(sizeof(char) * (size1 + size2 + 1));
	if (!joined)
	{
		free (start);
		return (NULL);
	}
	while (i < size1)
	{
		joined[i] = start[i];
		i++;
	}
	while (i < size1 + size2)
	{
		joined[i] = end[i - size1];
		i++;
	}
	joined[size1 + size2] = '\0';
	free (start);
	return (joined);
}

char	*ft_strchr(char *str, char c)
{
	int	i;
	
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* utils */

char	*find_line(int fd)
{
	char	*tmp;
	int		check;

	tmp = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	check = read(fd, tmp, BUFFER_SIZE);	
	if (check < 1)
	{
		free (tmp);
		return (NULL);
	}
	tmp[check] = '\0';
	return (tmp);
}

char	*fill_line(char **buff)
{
	char	*line;
	char	*nl;
	char	*next;

	nl = ft_strchr(*buff, '\n');
	if (nl)
	{
		line = (char *) malloc (sizeof(char) * (nl - *buff) + 2);
		if (!line)
			return (NULL);
		line = ft_strchcpy(line, *buff, '\n');
		next = ft_strdup(nl + 1);
		free (*buff);
		*buff = next;
	}
	else
	{
		line = ft_strdup(*buff);
		free (*buff);
		*buff = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*new;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new = find_line(fd);
	while (new)
	{
		if (!buff)
			buff = ft_strdup(new);
		else
			buff = ft_strjoin(buff, new);
		free (new);
		if (ft_strchr(buff, '\n'))
		{
			line = fill_line(&buff);
			return (line);
		}
		new = find_line(fd);
	}
	if (buff && *buff)
		return (fill_line(&buff));
	if (buff)
	{
		free (buff);
		buff = NULL;
	}
	return (NULL);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open ("test", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}