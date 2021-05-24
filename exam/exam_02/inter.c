#include <unistd.h>

unsigned char id[128];

int main(int ac, char **av)
{
	int i, j;

	if (ac == 3)
	{
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (av[i][j])
			{
				if (i == 2 && id[(unsigned char)av[i][j]] == 0)
					id[(unsigned char)av[i][j]] = 1;
				if (i == 1 && id[(unsigned char)av[i][j]] == 1)
				{
					write(1, &av[i][j], 1);
					id[(unsigned char)av[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
}

