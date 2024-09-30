#ifndef SERVER_CLIENT_UTILS_H
#define SERVER_CLIENT_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1000

void load_primes_from_file(int *primes, int *num_primes, char *filename);
int find_prime_factors(int *primes, int num_primes, int n, int *factors);

#endif /* SERVER_CLIENT_UTILS_H */
