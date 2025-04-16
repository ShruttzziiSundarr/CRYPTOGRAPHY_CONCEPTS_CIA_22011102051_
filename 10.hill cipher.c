#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int key[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    char plaintext[100];
    char ciphertext[100];
    int i, j, k;
    int p_len = 0;
    int matrix[3];
    int result[3];

    printf("Enter the plaintext (uppercase letters only, length multiple of 3): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isupper(plaintext[i])) {
            p_len++;
        }
    }

    if (p_len % 3 != 0) {
        printf("Plaintext length must be a multiple of 3.\n");
        return 1;
    }

    for (i = 0; i < p_len; i += 3) {
        for (j = 0; j < 3; j++) {
            matrix[j] = plaintext[i + j] - 'A';
        }

        for (j = 0; j < 3; j++) {
            result[j] = 0;
            for (k = 0; k < 3; k++) {
                result[j] += key[j][k] * matrix[k];
            }
            ciphertext[i + j] = (result[j] % 26) + 'A';
        }
    }
    ciphertext[p_len] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}