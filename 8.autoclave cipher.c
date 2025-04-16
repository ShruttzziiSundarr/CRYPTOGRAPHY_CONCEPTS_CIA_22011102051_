#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char encrypt_autokey_char(char plaintext_char, char key_char) {
    if (isalpha(plaintext_char) && isalpha(key_char)) {
        char base = isupper(plaintext_char) ? 'A' : 'a';
        int plaintext_val = plaintext_char - base;
        int key_val = key_char - base;
        int ciphertext_val = (plaintext_val + key_val) % 26;
        return (char)(ciphertext_val + base);
    }
    return plaintext_char;
}

void encrypt_autokey(char *plaintext, char *ciphertext, char *key) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    strcpy(ciphertext, "");
    for (int i = 0; i < plaintext_len; i++) {
        char current_key_char;
        if (i < key_len) {
            current_key_char = key[i];
        } else {
            current_key_char = plaintext[i - key_len];
        }
        ciphertext[i] = encrypt_autokey_char(plaintext[i], current_key_char);
    }
    ciphertext[plaintext_len] = '\0';
}

char decrypt_autokey_char(char ciphertext_char, char key_char) {
    if (isalpha(ciphertext_char) && isalpha(key_char)) {
        char base = isupper(ciphertext_char) ? 'A' : 'a';
        int ciphertext_val = ciphertext_char - base;
        int key_val = key_char - base;
        int plaintext_val = (ciphertext_val - key_val + 26) % 26;
        return (char)(plaintext_val + base);
    }
    return ciphertext_char;
}

void decrypt_autokey(char *ciphertext, char *plaintext, char *key) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    strcpy(plaintext, "");
    for (int i = 0; i < ciphertext_len; i++) {
        char current_key_char;
        if (i < key_len) {
            current_key_char = key[i];
        } else {
            current_key_char = plaintext[i - key_len];
        }
        plaintext[i] = decrypt_autokey_char(ciphertext[i], current_key_char);
    }
    plaintext[ciphertext_len] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char key[20];
    char decrypted_plaintext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the key (alphabetic): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    encrypt_autokey(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt_autokey(ciphertext, decrypted_plaintext, key);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}