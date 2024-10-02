#include "server_client_utils.h"

int main()
{
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[BUFFER_SIZE] = {0};
	int primes[MAX];    // Array to hold the first 1000 primes
	int num_primes = 0; // Number of primes read
	char response[BUFFER_SIZE];
	int client_number;
	int prime_factor;

	// Read primes from the 1000.txt file
	read_primes("1000.txt", primes, &num_primes);

	// Create socket, bind, and listen (same as before)
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0)
	{
		perror("listen failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("Waiting for connections...\n");
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
		{
			perror("accept failed");
			close(server_fd);
			exit(EXIT_FAILURE);
		}

		// Receive the number from the client
		read(new_socket, buffer, BUFFER_SIZE);
		client_number = atoi(buffer); // Convert the client's message to an integer
		printf("Number received from client: %d\n", client_number);

		// Get one prime factor of the received number
		prime_factor = get_prime_factor(client_number, primes, num_primes);

		// Send the prime factor back to the client
		if (prime_factor != -1)
		{
			sprintf(response, "One prime factor of %d is: %d", client_number, prime_factor);
		}
		else
		{
			sprintf(response, "No prime factor found for %d", client_number);
		}
		send(new_socket, response, strlen(response), 0);

		// Close the client socket
		close(new_socket);
	}

	// Close the server socket
	close(server_fd);

	return (0);
}