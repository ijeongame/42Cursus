#include <unistd.h>

unsigned char id[128];

int main(int ac, char **av)
{
	int i, j;

	if (ac == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if (id[(unsigned char)av[i][j]] == 0)
				{
					id[(unsigned char)av[i][j]] = 1;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
