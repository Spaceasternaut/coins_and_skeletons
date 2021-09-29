/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaseltz <skaseltz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:28:35 by skaseltz          #+#    #+#             */
/*   Updated: 2021/09/16 16:21:12 by skaseltz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlenchr(char const *s, char c);
char	*ft_strchr(char const *s, int c);
void	ft_rewrite_buf(char **buf, int i);
char	*ft_check_buf(char *buf, char *line, int *flag_buf);
char	*ft_strjoin(char const *s1, char const *s2);

# define BUFFER_SIZE 100

#endif
