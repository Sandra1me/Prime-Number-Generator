/*
    Prime Number Generator
    ----------------------
    This program allows users to find prime numbers within a specified range or generate all prime numbers up to a given number.

    Author: [Sandra Martin Elias]
    Date: [2025/08/11]
*/

#include<stdio.h>

// Used functions
int is_prime(int num); // Function to check if a number is prime
int primes_in_range(); // Function to find prime numbers in a specified range
int prime_generator(); // Function to generate all prime numbers up to a specified number

int main() 
{
    int contador, option;
    char cont = 'y';

    // Main loop, keeps running until user decides to exit
    while(cont=='y'){  
        contador=0;

        printf("Select what you want to do:\n1. Search prime in a range\n2. Generate all primes up to a number\n3. Exit\n");
        scanf("%i", &option);

        // Execute the selected option
        if (option ==1) {
            contador=primes_in_range();
        } else if (option ==2) {
            contador=prime_generator();
        } else if (option ==3) {
            break;
        } else {
            // Invalid option, prompt user to select a valid one
            printf("Invalid option. Please select 1, 2, or 3. Press enter to continue\n");
            while (getchar() != '\n' && getchar() != EOF);
            continue;
        }

        // Display the results
        printf("\n-----------------------------\n");
        printf("Total prime numbers found: %i\n", contador);

        // Ask if the user wants to continue
        while(1) {
            while (getchar() != '\n' && getchar() != EOF);
            printf("Do you want to continue? (y/n): ");
            scanf(" %c", &cont);

            if (cont=='y' || cont=='n') {
                break;
            } else {
                printf("Invalid input. Please enter y or n.\n");
            }
        } 
    }

    // Exit message
    printf("Thank you for using the prime number generator!\nBye!\n");

    return 0;
}

// Function to check if a number is prime 
// Returns 1 if prime, 0 otherwise  
int is_prime(int num) {
    int j, isprime=1, contador=0;

    for(j=2; j*j<=num; j++) {
        if (num%j==0) {
            return 0;
        }
    }

    printf("%i   ", num);
    return 1;
}

// Function to find prime numbers in a specified range
// Returns the count of prime numbers found
int primes_in_range() {
    int i, maxlim=0, minlim=0, contador=0;

    printf("Enter the upper limit (min value = 2): ");
    scanf("%i", &maxlim);

    printf("Enter the lower limit (min value = 2): ");
    scanf("%i", &minlim);

    if (maxlim <=1 || minlim <= 1) {
        printf("Please enter a positive number bigger than 1 for both limits.\n");
    } else if (maxlim < minlim) {
        printf("The upper limit must be greater than or equal to the lower limit.\n");
    } else {
        printf("Prime numbers from %i up to %i:\n", minlim, maxlim);
        
        for (i=minlim; i<=maxlim; i++) {
            contador+=is_prime(i);
        }
    }

    return contador;
}

// Function to generate all prime numbers up to a specified number
// Returns the count of prime numbers found
int prime_generator() {
    int maxlim=0, i, contador=0;

    printf("Enter the upper limit (min value = 2): ");
    scanf("%i", &maxlim);
    
    if (maxlim <= 1) {
        printf("Please enter a positive number bigger than 1.\n");
    } else {
        printf("Prime numbers up to %i:\n", maxlim);
        
        for (i=2; i<=maxlim; i++) {
            contador+= is_prime(i);
        }
    }

    return contador;
}