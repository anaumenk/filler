/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:07:01 by anaumenk          #+#    #+#             */
/*   Updated: 2018/01/13 16:07:02 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check(char **curr, int fd, char **line)
{
	char	*tmp;

	if (ft_strchr(curr[fd], '\n'))
	{
		if (curr[fd][0] == '\n')
		{
			*line = ft_strdup("\0");
			tmp = curr[fd];
			curr[fd] = ft_strdup(ft_strchr(curr[fd], '\n') + 1);
			free(tmp);
			return (1);
		}
		*line = ft_strsub(curr[fd], 0, (ft_strlen(curr[fd]) -
			ft_strlen(ft_strchr(curr[fd], '\n'))));
		tmp = curr[fd];
		curr[fd] = ft_strdup(ft_strchr(curr[fd], '\n') + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(curr[fd]);
		ft_bzero(curr[fd], ft_strlen(curr[fd]));
	}
	return (0);
}

int	ft_find_n(char **curr, int fd, char *buf)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = curr[fd];
	curr[fd] = ft_strjoin(curr[fd], buf);
	free(tmp);
	ft_bzero(buf, BUFF_SIZE + 1);
	while (curr[fd][i])
	{
		if (curr[fd][i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	**curr = NULL;
	int			ret;

	ret = 1;
	if (fd > 50000 || fd < 0 || BUFF_SIZE > 838491)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (curr == NULL)
		curr = (char**)malloc(sizeof(char*) * 50000);
	while (ret != 0)
	{
		if (curr[fd] == NULL)
			curr[fd] = ft_strnew(0);
		ret = (int)read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ft_find_n(curr, fd, buf))
			break ;
	}
	if (check(curr, fd, line))
		return (1);
	if ((*curr[fd] == '\0' && *line[0] == '\0') && (ret = -2))
		free(*line);
	return (ret == -2 ? 0 : 1);
}
