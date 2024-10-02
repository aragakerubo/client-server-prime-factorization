#ifndef SERVER_CLIENT_UTILS_H
#define SERVER_CLIENT_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1000
#define BUFFER_SIZE 1024

void read_primes_from_file(const char *filename, int *primes, int *num_primes);
int get_prime_factor(int number, int *primes, int num_primes)

#endif /* SERVER_CLIENT_UTILS_H */
