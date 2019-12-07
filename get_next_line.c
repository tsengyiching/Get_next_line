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

static void	ft_save(char **save, char *buf)
{
	char *temp;

	temp = *save;
	*save = ft_strjoin(temp, buf);
	free(temp);
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
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	int				index_charset;
	static t_stock	*save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!save)
	{
		if (!(save = malloc(sizeof(t_stock) * 1)))
			return (-1);
		save->str = 0;
		save->i = 0;
	}
	while (!(index_charset = ft_strchr((save->str), '\n')) && save->i == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		ft_save(&(save->str), buf);
		if (ft_strlen(buf) < BUFFER_SIZE)
		{
			save->i = 1;
			break ;
		}
	}
	if ((index_charset = ft_strchr((save->str), '\n')) > 0)
		ft_put_line(line, &(save->str), index_charset);
	else
	{
		*line = ft_substr((save->str), 0, ft_strlen(save->str));
		free(save->str);
		free(save);
	}
	return ((index_charset == 0) ? 0 : 1);
}
