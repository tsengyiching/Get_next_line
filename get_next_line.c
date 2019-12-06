/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yictseng <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 14:55:34 by yictseng     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:46:58 by yictseng    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_save(char **save, char *buf)
{
	char *temp;

	temp = *save;
	*save = ft_strjoin(temp, buf);
	if (*save[0] == '\0')
		free(*save);
	free(temp);
}

void	ft_put_line(char **line, char **save, int index_charset)
{
	char	*temp;

	*line = ft_substr(*save, 0, index_charset - 1);
	temp = ft_substr(*save, index_charset, ft_strlen(*save));
	free(*save);
	*save = temp;
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	static char		*save;
	int				index_charset;
	int				state;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	state = 1;
	while (!(index_charset = ft_strchr(save, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (!ft_strlen(buf))
			state = 0;
		ft_save(&save, buf);
		if (!state)
			break ;
	}
	if (index_charset > 0)
		ft_put_line(line, &save, index_charset);
	else
		*line = ft_substr(save, 0, ft_strlen(save));
	return ((index_charset == 0) ? 0 : 1);
}
