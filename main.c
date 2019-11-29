#include "get_next_line.h"

int main(void)
{
	char *line;
	int i = 1;
	int j = 1;
	line = NULL;
	int fd = open("text.txt", O_RDONLY);
	while (j == 1)
	{
		j = get_next_line(fd, &line);
		printf("--LIGNE  %d\n%s\n retour : %d\n\n\n", i, line, j);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
