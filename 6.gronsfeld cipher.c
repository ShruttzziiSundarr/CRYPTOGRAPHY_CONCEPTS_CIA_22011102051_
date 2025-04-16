#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char encrypt_gronsfeld_char(char ch, char key_digit) {
    if (isalpha(ch)) {
        int shift = key_digit - '0';
        char base = isupper(ch) ? 'A' : 'a';
        int char_index = ch - base;
        int encrypted_index = (char_index + shift) % 26;
        return (char)(encrypted_index + base);
    }
    return ch;
}

void encrypt_gronsfeld(char *plaintext, char *ciphertext, char *key) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = encrypt_gronsfeld_char(plaintext[i], key[i % key_len]);
    }
    ciphertext[plaintext_len] = '\0';
}

char decrypt_gronsfeld_char(char ch, char key_digit) {
    if (isalpha(ch)) {
        int shift = key_digit - '0';
        char base = isupper(ch) ? 'A' : 'a';
        int char_index = ch - base;
        int decrypted_index = (char_index - shift + 26) % 26;
        return (char)(decrypted_index + base);
    }
    return ch;
}

void decrypt_gronsfeld(char *ciphertext, char *plaintext, char *key) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = decrypt_gronsfeld_char(ciphertext[i], key[i % key_len]);
    }
    plaintext[ciphertext_len] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char key[20];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the numeric key (e.g., 123): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    encrypt_gronsfeld(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted_plaintext[100];
    decrypt_gronsfeld(ciphertext, decrypted_plaintext, key);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}