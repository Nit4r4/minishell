/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:23:27 by vferraro          #+#    #+#             */
/*   Updated: 2022/01/25 13:49:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_next(int fd, char *buff, char **fd_line)
{
	int		read_line;
	char	*stock;

	while (!ft_strchr(*fd_line, '\n'))
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		buff[read_line] = '\0';
		if (!*fd_line)
		{
			*fd_line = ft_substr(buff, 0, read_line);
		}
		else if (read_line == 0)
		{	
			free(buff);
			return ;
		}
		else
		{
			stock = *fd_line;
			*fd_line = ft_strjoin(*fd_line, buff);
			free(stock);
		}
	}
	free(buff);
}

char	*line(char **fd_line)
{
	int		i;
	int		j;
	char	*ret;
	char	*stock;

	if (!*fd_line)
		return (NULL);
	if (!ft_strchr(*fd_line, '\n'))
	{
		ret = ft_substr(*fd_line, 0, ft_strlen(*fd_line));
		free(*fd_line);
		*fd_line = 0;
		if (ret[0] == '\0')
			free (ret);
		else if (ret[0] != '\0')
			return (ret);
		return (NULL);
	}
	i = ft_strlen(*fd_line);
	j = ft_strlen(ft_strchr(*fd_line, '\n'));
	ret = ft_substr(*fd_line, 0, i - j + 1);
	stock = *fd_line;
	*fd_line = ft_substr(ft_strchr(*fd_line, '\n'), 1, j);
	free(stock);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*fd_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!fd_line)
	{
		fd_line = malloc(sizeof(char) * 1);
		fd_line[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	get_next(fd, buffer, &fd_line);
	return (line(&fd_line));
}
