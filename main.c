#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	(void)ac;
	i = 1;
	fd = open(av[1], O_RDONLY);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("|%d|", i);
		printf("  '%s'\n", line);
		free(line);
	}
	return (0);
}