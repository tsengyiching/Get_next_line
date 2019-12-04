#include "get_next_line.h"

int main(int ac, char **av)
{
    char *line;
    int ret, fd;
    
    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    while (1)
    {
        ret = get_next_line(fd, &line);
        printf("[%d] [%d] '%s'\n", fd, ret, line);
        free(line);
        if (ret <= 0)
            break;
    }
    close(fd);
    return (0);
}
