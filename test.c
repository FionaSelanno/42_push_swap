#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;

	printf("argc: %d\n", argc);
	i = 0;
	while(argc > i)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}
