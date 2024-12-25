/*Implement the Rabin-Karp algorithm for string matching
 • Take user input of both the strings 
 • Write proper statements for user input
Name- Sanya Agarwal 
Roll no. - R2142230839
Sap id. - 500120145
Date - 30-11-24
*/

#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

// Rabin-Karp Algorithm
void rabinKarp(char text[], char pattern[], int prime) {
    int n = strlen(text);    // Length of the text
    int m = strlen(pattern); // Length of the pattern
    int patternHash = 0;     // Hash value for the pattern
    int textHash = 0;        // Hash value for the text
    int hashFactor = 1;      // The hash factor: d^(m-1) % prime
    int i, j;

    // Calculate the hash factor (d^(m-1) % prime)
    for (i = 0; i < m - 1; i++) {
        hashFactor = (hashFactor * d) % prime;
    }

    // Calculate the initial hash values for the pattern and the first window of text
    for (i = 0; i < m; i++) {
        patternHash = (d * patternHash + pattern[i]) % prime;
        textHash = (d * textHash + text[i]) % prime;
    }

    // Slide the pattern over the text
    for (i = 0; i <= n - m; i++) {
        // Check if the current hash values of text and pattern match
        if (patternHash == textHash) {
            // If the hashes match, check character by character
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If the pattern matches, print the starting index
            if (j == m) {
                printf("Pattern found at index %d\n", i);
            }
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            textHash = (d * (textHash - text[i] * hashFactor) + text[i + m]) % prime;

            // Convert negative hash values to positive
            if (textHash < 0) {
                textHash += prime;
            }
        }
    }
}

int main() {
    char text[1000], pattern[1000];
    int prime = 101; // A prime number for hashing

    // User Input
    printf("Rabin-Karp Algorithm for String Matching\n");
    printf("Enter the main string (text): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove the newline character

    printf("Enter the substring to search for (pattern): ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0; // Remove the newline character

    // Edge case check
    if (strlen(pattern) > strlen(text)) {
        printf("Error: Pattern length cannot exceed text length.\n");
    } else {
        // Call the Rabin-Karp function
        rabinKarp(text, pattern, prime);
    }

    return 0;
}
