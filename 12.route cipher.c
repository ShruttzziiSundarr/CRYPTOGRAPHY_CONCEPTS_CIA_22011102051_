#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptRouteCipher(char *plaintext, int rows, int cols, char *ciphertext) {
    int len = strlen(plaintext);
    if (len != rows * cols) {
        printf("Plaintext length must be equal to rows * columns for this simple implementation.\n");
        strcpy(ciphertext, "");
        return;
    }
    char grid[rows][cols];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = plaintext[k++];
        }
    }
    k = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            ciphertext[k++] = grid[i][j];
        }
    }
    ciphertext[k] = '\0';
}

void decryptRouteCipher(char *ciphertext, int rows, int cols, char *plaintext) {
    int len = strlen(ciphertext);
    if (len != rows * cols) {
        printf("Ciphertext length must be equal to rows * columns for this simple implementation.\n");
        strcpy(plaintext, "");
        return;
    }
    char grid[rows][cols];
    int k = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            grid[i][j] = ciphertext[k++];
        }
    }
    k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            plaintext[k++] = grid[i][j];
        }
    }
    plaintext[k] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char decryptedText[100];
    int rows, cols;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    while (getchar() != '\n');

    if (strlen(plaintext) != rows * cols) {
        printf("Error: Plaintext length must be equal to rows * columns.\n");
        return 1;
    }

    encryptRouteCipher(plaintext, rows, cols, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decryptRouteCipher(ciphertext, rows, cols, decryptedText);
    printf("Decrypted plaintext: %s\n", decryptedText);

    return 0;
}