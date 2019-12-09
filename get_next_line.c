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
#include <string.h>

static int	ft_read_line(t_stock *tab, int fd)
{
	int		ret;
	int		index_charset;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	while (!(index_charset = ft_strchr((tab->str), '\n')) && tab->state == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		temp = tab->str;
		tab->str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strlen(buf) < BUFFER_SIZE)
		{
			tab->state = 1;
			break ;
		}
	}
	return (index_charset);
}

static void	ft_put_line(char **line, char **save, int index_charset)
{
	char	*temp;

	*line = ft_substr(*save, 0, index_charset - 1);
	temp = ft_substr(*save, index_charset, ft_strlen(*save));
	free(*save);
	*save = temp;
}

int			get_next_line(int fd, char **line)
{
	int				index_charset;
	static t_stock	tab;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!tab.str)
	{
		//tab.str = 0;
		tab.state = 0;
	}
	index_charset = ft_read_line(&tab, fd);
	if ((index_charset = ft_strchr((tab.str), '\n')) > 0)
		ft_put_line(line, &(tab.str), index_charset);
	else
	{
		*line = ft_substr((tab.str), 0, ft_strlen(tab.str));
		free(tab.str);
	}
	return ((index_charset == 0) ? 0 : 1);
}
