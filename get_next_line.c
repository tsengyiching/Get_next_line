/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yictseng <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 14:55:34 by yictseng     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 14:57:30 by yictseng    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 1

// int		get_next_line(int fd, char **line)
// {
//     int             ret;
//     static char     *temp;
//     char            buf[BUFFER_SIZE + 1];

//     while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
//     {
        // buf[ret] = '\0';
        // if (ft_strchr(buf, '\n'))
        //     save = ft_strjoin(temp, buf);
        // else
        //     temp = ft_strdup(buf);
        // if (ft_strchr(buf, '\n'))
        //     break ;
//     }
//     if (buf)
//         return (1);
// }


int main()
{
    int         fd;
    int         ret;
    char        *temp;
    char        **line;
    static char *save = NULL;
    char        buf[BUFFER_SIZE + 1];

    fd = open("text.txt", O_RDONLY);
    if (!(line = malloc(sizeof(*line))))
        return (-1);
    if (!(*line = malloc(sizeof(**line))))
        return (-1);
    *line[0] = 0;
    if (fd == -1)
    {
        printf("ERROR");
        return (1);
    }
    while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        save = ft_strjoin(*line, buf);
        printf("%s\n", save);
        free(*line);
        *line = save;
        if (ft_strchr(buf, '\n'))
            break ;
    }
    printf("%s\n", *line);
    if (close(fd) == -1)
    {
        printf("close error");
        return (1);
    }
    free(*line);
    free(line);
    return (0);
}