import socket  # For network communication

BUFFER_SIZE = 1024  # Constant for buffer size
PORT = 8080  # The port number to connect to on the server
SERVER_IP = "127.0.0.1"  # Server IP address (localhost)
MAX_NUMBER = 200000000  # Maximum number that can be sent to the server


def get_valid_number():
    """Prompt the user to input a valid integer."""
    while True:
        user_input = input("Enter a number: ")  # Ask user for input

        # Check if the input is a valid integer
        if not user_input.isdigit():
            print(
                "Invalid input. Please enter a valid number."
            )  # Prompt again if invalid
            continue
        elif int(user_input) > MAX_NUMBER:
            print(f"Number must be less than {MAX_NUMBER}.")
            continue
        else:
            return int(user_input)  # Return the valid integer


def main():
    # Create a TCP/IP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Connect the socket to the server's port
        client_socket.connect((SERVER_IP, PORT))

        # Get a valid number from the user
        number = get_valid_number()

        # Send the number to the server as a string
        client_socket.sendall(str(number).encode("utf-8"))
        print(f"Number sent to server: {number}")

        # Receive and print the server's response
        response = client_socket.recv(BUFFER_SIZE).decode("utf-8")
        print(f"Message from server: {response}")

    except ConnectionError:
        print("Failed to connect to the server.")

    finally:
        # Close the socket connection
        client_socket.close()


if __name__ == "__main__":
    main()
