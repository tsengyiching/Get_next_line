#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int i = 1;
	int j = 1;
	line = NULL;
	int fd = open(av[1], O_RDONLY);
	(void)ac;
	while (j == 1)
	{
		j = get_next_line(fd, &line);
		printf("--LIGNE  %d\n%s\n", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
