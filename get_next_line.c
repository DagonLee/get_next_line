/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:13:28 by da-lee            #+#    #+#             */
/*   Updated: 2021/02/11 18:59:59 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_line_process(char *save, char **line)
{
	unsigned int	cnt;
	char			*tmp;

	cnt = 0;
	while (save[cnt])
	{
		if (save[cnt] == '\n')
			break ;
		cnt++;
	}
	if (cnt < ft_strlen(save))
	{
		*line = ft_substr(save, 0, cnt);
		tmp = ft_substr(save, cnt + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
	{
		*line = save;
		save = 0;
	}
	return (save);
}

int					ft_result(int r, char **save, char **line)
{
	if (r < 0)
		return (-1);
	else if (!*save)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		*save = ft_line_process(*save, line);
		if (!*save)
			return (0);
		return (1);
	}
}

int					get_next_line(int fd, char **line)
{
	static char		*save[MAX_FD];
	char			buffer[BUFFER_SIZE + 1];
	int				r;
	char			*tmp;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = 0;
		if (!save[fd])
			save[fd] = ft_strdup("");
		tmp = ft_strjoin(save[fd], buffer);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_result(r, &save[fd], line));
}
