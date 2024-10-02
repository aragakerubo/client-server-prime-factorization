#include "server_client_utils.h"

// Function to read the first 1000 primes from a file and store them in an array
void read_primes_from_file(const char *filename, int *primes, int *num_primes)
{
	int prime;
	int i;

	FILE *file = fopen(filename, "r"); // Open file for reading
	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	*num_primes = 0;

	// Read primes from file into the array
	while (fscanf(file, "%d", &prime) != EOF && *num_primes < 1000)
	{
		primes[(*num_primes)++] = prime;
	}

	fclose(file); // Close the file after reading
}

// Function to return one prime factor of a given number
int get_prime_factor(int number, int *primes, int num_primes)
{
	// Try dividing the number by each prime from the array
	for (i = 0; i < num_primes; i++)
	{
		if (number % primes[i] == 0)
		{
			return (primes[i]); // Return the first prime factor found
		}
	}
	return (-1); // If no prime factor is found, return -1
}