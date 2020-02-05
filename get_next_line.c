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

static int	ft_read_line(t_stock *save, int fd)
{
	int		ret;
	int		index_charset;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	while (!(index_charset = ft_strchr((save->str), '\n')) && save->eof == 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		temp = save->str;
		save->str = ft_strjoin(temp, buf);
		if (temp != NULL)
			free(temp);
		if (ft_strlen(buf) < BUFFER_SIZE)
		{
			save->eof = 1;
			break ;
		}
	}
	return (index_charset);
}

int			get_next_line(int fd, char **line)
{
	int				index_charset;
	char			*temp;
	static t_stock	save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!save.str)
		save.eof = 0;
	if ((index_charset = ft_read_line(&save, fd)) == -1)
		return (-1);
	if ((index_charset = ft_strchr((save.str), '\n')) > 0)
	{
		*line = ft_substr(save.str, 0, index_charset - 1);
		temp = ft_substr(save.str, index_charset, ft_strlen(save.str));
		free(save.str);
		save.str = temp;
	}
	else
	{
		*line = ft_substr((save.str), 0, ft_strlen(save.str));
		free(save.str);
		save.str = 0;
	}
	return ((index_charset == 0) ? 0 : 1);
}
