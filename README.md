# **Client-Server Prime Factorization**

This project implements a client-server application that checks if a given integer is the product of two prime numbers. The application uses socket programming to allow communication between the client and server.

## **Table of Contents**

-   [Overview](#overview)
-   [Features](#features)
-   [Project Structure](#project-structure)
-   [Requirements](#requirements)
-   [Usage](#usage)
-   [Compilation and Execution](#compilation-and-execution)
-   [License](#license)

## **Overview**

This client-server application, written in C, demonstrates socket programming. The client sends an integer to the server, and the server checks if the integer can be expressed as the product of two primes from a list of the first 1,000 prime numbers (up to 7919). If the product of two primes is found, the server responds with one of the prime factors.

## **Features**

-   **Server**:
    -   Receives an integer from the client.
    -   Checks if the integer is a product of two primes from a predefined list.
    -   Sends one of the prime factors back to the client.
-   **Client**:
    -   Captures an integer from the user.
    -   Sends the integer to the server.
    -   Receives a prime factor or an error message from the server.
-   **Modularized**:
    -   Common functions (prime number loading, factorization check) are stored in separate utility files.

## **Project Structure**

```
client-server-prime-factorization/
│
├── server_client_utils.h       # Header file containing shared function declarations
├── server_client_utils.c       # Source file containing the implementation of shared functions
├── server.c                    # Server-side code to handle prime factorization logic
├── client.c                    # Client-side code for interacting with the server
├── 1000.txt                    # List of the first 1,000 prime numbers
└── README.md                   # This README file
```

## **Requirements**

-   A C compiler (e.g., `gcc`)
-   A terminal or command prompt
-   Prime numbers file: Download the file of the first 1,000 prime numbers from [here](https://t5k.org/lists/small/1000.txt) and save it as `1000.txt` in the project directory.

## **Usage**

### **Client-Server Communication:**

1. The client accepts an integer input from the user.
2. The server checks if the number is a product of two prime numbers.
3. If it is, the server returns one of the prime factors to the client.
4. If not, the server sends an error message indicating no prime factors were found.

## **Compilation and Execution**

### 1. **Clone the repository:**

```bash
git clone https://github.com/yourusername/client-server-prime-factorization.git
cd client-server-prime-factorization
```

### 2. **Compile the code:**

#### Compile both server and client along with the utility functions:

```bash
gcc server.c server_client_utils.c -o server
gcc client.c -o client
```

### 3. **Run the server:**

Run this in a separate terminal:

```bash
./server
```

The server will start and listen for incoming connections.

### 4. **Run the client:**

Run the client in another terminal:

```bash
./client
```

The client will prompt you to input an integer and display the response from the server.

### **Example:**

```
Enter an integer: 77
Server response: 7
```

In this example, 77 is the product of two primes (7 and 11), so the server returns one of the factors.

## **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
