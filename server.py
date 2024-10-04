import socket  # For network communication

BUFFER_SIZE = 1024  # Constant for buffer size
PORT = 8080  # Port for the server to listen on
IP_ADDRESS = "0.0.0.0"  # IP address for the server to listen on


# Function to load the first 1000 prime numbers from a file (1000.txt)
def load_primes():
    with open("1000.txt", "r") as f:
        primes = [
            int(line.strip()) for line in f.readlines()
        ]  # Read each line as an integer
    return primes


# Function to find a prime factor of the number from the list of primes
def find_prime_factor(number, primes):
    for prime in primes:
        if number % prime == 0:  # If prime is a factor of number
            return prime
    return None  # Return None if no prime factor is found (though this should not happen with proper input)


def main():
    # Load the first 1000 primes from the file
    primes = load_primes()

    # Create a TCP/IP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to the port
    server_socket.bind((IP_ADDRESS, PORT))

    # Listen for incoming connections
    server_socket.listen(5)
    print(f"Server listening on port {PORT}")

    while True:
        # Wait for a connection from the client
        client_socket, client_address = server_socket.accept()
        print(f"Connection from {client_address}")

        try:
            # Receive the number from the client
            data = client_socket.recv(BUFFER_SIZE).decode("utf-8")
            if not data:
                break  # If no data is received, break the loop

            # Convert the received data to an integer
            number = int(data)
            print(f"Received number from client: {number}")

            # Find a prime factor of the number
            prime_factor = find_prime_factor(number, primes)

            # If a prime factor is found, send it to the client
            if prime_factor:
                response = f"One prime factor of {number} is: {prime_factor}"
            else:
                response = f"No prime factor found for {number}."

            client_socket.sendall(
                response.encode("utf-8")
            )  # Send the response back to the client
            print(f"Sent response to client: {response}")

        except Exception as e:
            print(f"Error: {e}")

        finally:
            # Close the connection with the client
            client_socket.close()


if __name__ == "__main__":
    main()
