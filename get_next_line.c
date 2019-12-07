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

static char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(dst = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

static void	ft_save(char **save, char *buf)
{
	char *temp;

	temp = *save;
	*save = ft_strjoin(temp, buf);
	if (*save[0] == '\0')
		free(*save);
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
	static char		*save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(index_charset = ft_strchr(save, '\n')))
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)))
		{
			buf[ret] = '\0';
			ft_save(&save, buf);
			if (ft_strlen(buf) < BUFFER_SIZE)
				break ;
		}
	}
	if ((index_charset = ft_strchr(save, '\n')) > 0)
		ft_put_line(line, &save, index_charset);
	else
		*line = ft_substr(save, 0, ft_strlen(save));
	return ((index_charset == 0) ? 0 : 1);
}
