/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:19:24 by jhong             #+#    #+#             */
/*   Updated: 2022/03/18 23:12:53 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strchr(const char *s, int c)
{
	unsigned char	tmp;
	int				i;

	i = 0;
	if (!s)
		return (-1);
	tmp = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == tmp)
			return (i);
		i++;
	}
	if (tmp == '\0')
		return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char		*buf[4096];
	char			*line;
	size_t			prev_len;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (gnl_strchr(buf[fd], '\n') == -1)
	{
		prev_len = ft_strlen(buf[fd]);
		buf[fd] = insert_buffer(buf[fd], fd);
		if (prev_len == ft_strlen(buf[fd]) && buf[fd])
			line = ft_substr(buf[fd], 0, ft_strlen(buf[fd]));
	}
	if (!buf[fd])
		return (NULL);
	if (!line && gnl_strchr(buf[fd], '\n') != -1)
		line = ft_substr(buf[fd], 0, gnl_strchr(buf[fd], '\n') + 1);
	if (line)
	{
		buf[fd] = delete_buffer(buf[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*delete_buffer(char *buf, char *line)
{
	char		*new_buf;
	int			line_len;

	if (!buf || !line)
		return (buf);
	line_len = ft_strlen(line);
	if ((int)ft_strlen(buf) == line_len)
	{
		free(buf);
		return (NULL);
	}
	new_buf = ft_substr(buf, line_len, ft_strlen(buf) - line_len);
	free(buf);
	return (new_buf);
}

char	*insert_buffer(char *buf, int fd)
{
	char		*new_buf;
	int			new_len;
	char		*tmp;

	tmp = new_read(fd);
	if (!tmp)
		return (NULL);
	if (!tmp[0])
	{
		free(tmp);
		return (buf);
	}
	if (!buf)
		return (tmp);
	new_len = ft_strlen(buf) + ft_strlen(tmp);
	new_buf = malloc(new_len + 1);
	if (!new_buf)
		return (NULL);
	ft_strlcpy(new_buf, buf, new_len + 1);
	ft_strlcat(new_buf, tmp, new_len + 1);
	free(buf);
	free(tmp);
	return (new_buf);
}

char	*new_read(int fd)
{
	char		*tmp;
	int			nbytes;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	nbytes = read(fd, tmp, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[nbytes] = '\0';
	return (tmp);
}
