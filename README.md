# **Client-Server Prime Factorization**

This project implements a client-server application that checks if a given integer has a prime factor from a predefined list of the first 1,000 prime numbers. The application uses socket programming to allow communication between the client and server.

## **Table of Contents**

-   [Overview](#overview)
-   [Features](#features)
-   [Project Structure](#project-structure)
-   [Requirements](#requirements)
-   [Usage](#usage)
-   [Execution](#execution)
-   [License](#license)

## **Overview**

This client-server application, written in Python, demonstrates socket programming. The client sends an integer to the server, and the server checks if the integer has a prime factor from a list of the first 1,000 prime numbers (up to 7919). If a prime factor is found, the server responds with that factor; otherwise, it returns an error message.

## **Features**

-   **Server**:
    -   Receives an integer from the client.
    -   Checks if the integer has a prime factor from a predefined list (`1000.txt`).
    -   Sends the prime factor back to the client or an error message if no factors are found.
-   **Client**:
    -   Captures an integer from the user.
    -   Sends the integer to the server.
    -   Receives a prime factor or an error message from the server.
-   **Modularized**:
    -   Utilizes a file (`1000.txt`) containing the first 1,000 prime numbers for prime factorization.

## **Project Structure**

```
client-server-prime-factorization/
│
├── client.py                   # Client-side code for interacting with the server
├── server.py                   # Server-side code to handle prime factorization logic
├── 1000.txt                    # List of the first 1,000 prime numbers
├── .gitignore                  # Git ignore file to exclude unnecessary files
└── README.md                   # This README file
```

## **Requirements**

-   Python 3.x installed on your system.
-   `1000.txt` file with the first 1,000 prime numbers. You can download this from [here](https://t5k.org/lists/small/1000.txt).

## **Usage**

### **Client-Server Communication:**

1. The client accepts an integer input from the user.
2. The client sends this number to the server.
3. The server checks if the number has a prime factor from the list of prime numbers.
4. The server responds with a prime factor or an error message if no factors are found.

## **Execution**

### 1. **Clone the repository:**

```bash
git clone https://github.com/aragakerubo/client-server-prime-factorization.git
cd client-server-prime-factorization
```

### 2. **Prepare the prime numbers file (`1000.txt`):**

Ensure that you have a file named `1000.txt` in the same directory. This file should contain the first 1,000 prime numbers, one number per line.

### 3. **Run the server:**

Open a terminal and start the server by running:

```bash
python3 server.py
```

The server will start and listen for incoming client connections on `0.0.0.0:8080`.

```bash
Server listening on port 8080
```

### 4. **Run the client:**

In another terminal, run the client:

```bash
python3 client.py
```

The client will prompt you to input an integer. After sending the number to the server, the client will display the server's response.

### **Example:**

```
Enter a number: 77
Number sent to server: 77
Message from server: One prime factor of 77 is: 7
```

In this example, 77 is divisible by the prime number 7, so the server returns one of the prime factors.

From the terminal running the server we see:

```bash
Server listening on port 8080
Connection from ('127.0.0.1', 54441)
Received number from client: 77
Sent response to client: One prime factor of 77 is: 7
```

### **Common Errors:**

-   **Invalid Input (Client)**: If the user enters a non-numeric value, the client will keep asking until a valid number is provided.
-   **File Errors (Server)**: If the server cannot find `1000.txt`, it will display an error message and stop.

---

## **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
