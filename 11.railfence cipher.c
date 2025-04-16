#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptRailFence(char *plaintext, int rails, char *ciphertext) {
    int len = strlen(plaintext);
    char rail[rails][len];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            rail[i][j] = '\0';
        }
    }
    int row = 0, col = 0, down = 1;
    for (int i = 0; i < len; i++) {
        rail[row][col++] = plaintext[i];
        if (row == rails - 1) {
            down = 0;
        } else if (row == 0) {
            down = 1;
        }
        if (down) {
            row++;
        } else {
            row--;
        }
    }
    int k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] != '\0') {
                ciphertext[k++] = rail[i][j];
            }
        }
    }
    ciphertext[k] = '\0';
}

void decryptRailFence(char *ciphertext, int rails, char *plaintext) {
    int len = strlen(ciphertext);
    char rail[rails][len];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            rail[i][j] = '\0';
        }
    }
    int row = 0, col = 0, down = 1;
    for (int i = 0; i < len; i++) {
        rail[row][col++] = '*';
        if (row == rails - 1) {
            down = 0;
        } else if (row == 0) {
            down = 1;
        }
        if (down) {
            row++;
        } else {
            row--;
        }
    }
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] == '*') {
                rail[i][j] = ciphertext[index++];
            }
        }
    }
    row = 0, col = 0, down = 1;
    for (int i = 0; i < len; i++) {
        plaintext[i] = rail[row][col++];
        if (row == rails - 1) {
            down = 0;
        } else if (row == 0) {
            down = 1;
        }
        if (down) {
            row++;
        } else {
            row--;
        }
    }
    plaintext[len] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char decryptedText[100];
    int rails;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    while (getchar() != '\n');

    encryptRailFence(plaintext, rails, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decryptRailFence(ciphertext, rails, decryptedText);
    printf("Decrypted plaintext: %s\n", decryptedText);

    return 0;
}