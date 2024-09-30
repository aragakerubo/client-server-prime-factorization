#include "server_client_utils.h"

void load_primes_from_file(int *primes, int *num_primes, char *filename)
{
	FILE *file = fopen(filename, "r");
	int i = 0;

	if (file == NULL)
	{
		perror("Error opening file");
		exit(1);
	}

	while (fscanf(file, "%d", &primes[i]) != EOF)
	{
		i++;
	}

	*num_primes = i;
	fclose(file);
}

int find_prime_factors(int *primes, int num_primes, int n, int *factors)
{
	int i = 0;
	int j = 0;
	while (n > 1)
	{
		if (n % primes[i] == 0)
		{
			factors[j] = primes[i];
			j++;
			n /= primes[i];
		}
		else
		{
			i++;
		}
	}

	return j;
}