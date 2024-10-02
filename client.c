#include "server_client_utils.h"

int main()
{
	int sock = 0;			// File descriptor for the client socket
	struct sockaddr_in serv_addr;	// Structure to hold the server address
	char message[BUFFER_SIZE];	// Buffer to store the message to send to the server
	char buffer[BUFFER_SIZE] = {0}; // Buffer to store the response from the server

	// Creating a socket (IPv4, TCP, default protocol)
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n"); // Print error if socket creation fails
		return (-1);			       // Return error code if socket creation fails
	}

	// Define the server address (IPv4, port)
	serv_addr.sin_family = AF_INET;	  // Address family: IPv4
	serv_addr.sin_port = htons(PORT); // Convert port number to network byte order

	// Convert IP address from text to binary form (127.0.0.1 is localhost)
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n"); // Print error if conversion fails
		return (-1);					       // Return error code if conversion fails
	}

	// Connect to the server using the specified address and port
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n"); // Print error if the connection fails
		return (-1);			  // Return error code if connection fails
	}

	int number; // Variable to hold the user input
	while (1)
	{ // Infinite loop until valid input is received
		// Prompt the user to enter a number
		printf("Enter a number: "); // Ask user for input

		// Read an integer from the user and check if it's valid
		char input[BUFFER_SIZE];	  // Buffer to hold user input as a string
		fgets(input, BUFFER_SIZE, stdin); // Read input as a string

		// Validate the input to ensure it's a number
		char *endptr;			     // Pointer to track where the conversion ends
		number = strtol(input, &endptr, 10); // Convert input string to long

		// Check for conversion errors or if no digits were entered
		if (endptr == input || *endptr != '\n')
		{
			printf("Invalid input. Please enter a valid number.\n"); // Inform user of invalid input
			continue;						 // Ask for input again
		}
		break; // Valid input received; exit the loop
	}

	// Send the number to the server
	sprintf(message, "%d", number);		       // Format the number as a string
	send(sock, message, strlen(message), 0);       // Send the number to the server
	printf("Number sent to server: %d\n", number); // Confirm the number was sent

	// Read the response from the server
	read(sock, buffer, BUFFER_SIZE);	     // Read up to BUFFER_SIZE bytes from the server socket
	printf("Message from server: %s\n", buffer); // Print the server's response

	// Close the client socket after communication is done
	close(sock);

	return (0); // Exit the program
}