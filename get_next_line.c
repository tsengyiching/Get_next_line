/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yictseng <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 14:55:34 by yictseng     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:08:18 by yictseng    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*temp1;
	char			*temp2;
	char			*cut;
	static char		*save = NULL;

	if (!save)
	{
		if (!(save = malloc(sizeof(*save) * (BUFFER_SIZE + 1))))
			return (-1);
		save[0] = '\0';
	}
	*line = ft_strjoin("", save);
	while ((ret = read(fd, save, BUFFER_SIZE)) > 0)
	{
		save[ret] = '\0';
		temp1 = ft_split(save);
		temp2 = ft_strjoin(line[0], temp1);
		free(temp1);
		free(*line);
		*line = temp2;
		if (ft_strchr(save, '\n'))
		{
			cut = ft_strchr(save, '\n');
			free(save);
			save = ft_strjoin("", cut);
			break ;
		}
	}
	(ret > 0 ? ret = 1 : 0);
	if (ret == 0)
	{
		free(save);
		save = 0;
	}
	return (ret);
}
