#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}


char encrypt_affine_char(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        int char_index = ch - base;
        int encrypted_index = (a * char_index + b) % 26;
        return (char)(encrypted_index + base);
    }
    return ch; // Non-alphabetic characters remain unchanged
}


void encrypt_affine(char *plaintext, char *ciphertext, int a, int b) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = encrypt_affine_char(plaintext[i], a, b);
    }
    ciphertext[i] = '\0';
}

char decrypt_affine_char(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        int char_index = ch - base;
        int a_inverse = modInverse(a, 26);
        if (a_inverse == -1) {
            fprintf(stderr, "Error: Modular inverse of 'a' does not exist.\n");
            exit(EXIT_FAILURE);
        }
        int decrypted_index = (a_inverse * (char_index - b + 26)) % 26;
        return (char)(decrypted_index + base);
    }
    return ch; 
}


void decrypt_affine(char *ciphertext, char *plaintext, int a, int b) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = decrypt_affine_char(ciphertext[i], a, b);
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    int a, b;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; 

    printf("Enter the value of 'a' (must be coprime with 26, e.g., 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25): ");
    scanf("%d", &a);
    while (getchar() != '\n'); 

    printf("Enter the value of 'b' (shift value): ");
    scanf("%d", &b);
    while (getchar() != '\n'); 

   
    encrypt_affine(plaintext, ciphertext, a, b);
    printf("Ciphertext: %s\n", ciphertext);

    // Decryption
    char decrypted_plaintext[100];
    decrypt_affine(ciphertext, decrypted_plaintext, a, b);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}