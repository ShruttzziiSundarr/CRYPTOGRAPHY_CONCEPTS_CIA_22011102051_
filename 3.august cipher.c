#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a single character with ROT1
char encrypt_char_rot1(char ch) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)(((ch - base + 1) % 26) + base);
    }
    return ch; // Non-alphabetic characters remain unchanged
}

// Function to encrypt a string with ROT1
void encrypt_rot1(char *plaintext, char *ciphertext) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = encrypt_char_rot1(plaintext[i]);
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext
}

int main() {
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove trailing newline

    encrypt_rot1(plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}