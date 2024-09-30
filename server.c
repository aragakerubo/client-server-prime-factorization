#include "server_client_utils.h"

int main(void)
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[MAX] = {0};
	char *hello = "Hello from server";
	int primes[MAX];
	int num_primes;
	int factors[MAX];
	int num_factors;

	load_primes_from_file(primes, &num_primes, "1000.txt");

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	valread = read(new_socket, buffer, MAX);
	printf("%s\n", buffer);
	num_factors = find_prime_factors(primes, num_primes, atoi(buffer), factors);

	send(new_socket, factors, num_factors * sizeof(int), 0);
	printf("Factors sent\n");

	return 0;
}