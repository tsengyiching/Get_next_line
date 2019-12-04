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

int     get_next_line(int fd, char **line)
{
    int                ret;
    char               *temp1;
    char               *temp2;
    char               buf[BUFFER_SIZE + 1];
    static char        *save;
    int                indexCharset;
    int                state;
    
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    state = 1;
    while (!(indexCharset = ft_strchr(save, '\n')))
    {
        ret = read(fd, buf, BUFFER_SIZE);
        buf[ret] = '\0';
        if (!ft_strlen(buf))
            state = 0;
        temp2 = save;
        save = ft_strjoin(temp2, buf);
        free(temp2);
        if (!state)
            break;
    }
    temp1 = NULL;
    if (indexCharset > 0)
    {
        *line = ft_substr(save, 0, indexCharset - 1);
        temp1 = ft_substr(save, indexCharset, ft_strlen(save));
        free(save);
        save = temp1;
    }
    else
        *line = ft_substr(save, 0, ft_strlen(save));
    return ((indexCharset == 0) ? 0 : 1);
}
