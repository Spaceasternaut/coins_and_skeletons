/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:32 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/11 13:28:34 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			flag_buf;
	int			read_byte;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd > OPEN_MAX)
		return (-1);
	*line = 0;
	*line = ft_check_buf(buf, *line, &flag_buf);
	read_byte = 1;
	while (read_byte && !flag_buf)
	{
		read_byte = (int)read(fd, buf, BUFFER_SIZE);
		if (read_byte < 0)
			return (-1);
		buf[read_byte] = 0;
		if (!ft_strchr(buf, '\n'))
			*line = ft_strjoin(*line, buf);
		else
			*line = ft_check_buf(buf, *line, &flag_buf);
	}
	if (read_byte == 0)
		return (0);
	return (1);
}
