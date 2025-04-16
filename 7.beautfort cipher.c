#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char encrypt_beaufort_char(char plaintext_char, char key_char) {
    if (isalpha(plaintext_char) && isalpha(key_char)) {
        char base_plaintext = isupper(plaintext_char) ? 'A' : 'a';
        char base_key = isupper(key_char) ? 'A' : 'a';
        int plaintext_val = plaintext_char - base_plaintext;
        int key_val = key_char - base_key;
        int ciphertext_val = (key_val - plaintext_val + 26) % 26;
        return (char)(ciphertext_val + base_plaintext);
    }
    return plaintext_char;
}

void encrypt_beaufort(char *plaintext, char *ciphertext, char *key) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = encrypt_beaufort_char(plaintext[i], key[i % key_len]);
    }
    ciphertext[plaintext_len] = '\0';
}

char decrypt_beaufort_char(char ciphertext_char, char key_char) {
    if (isalpha(ciphertext_char) && isalpha(key_char)) {
        char base_ciphertext = isupper(ciphertext_char) ? 'A' : 'a';
        char base_key = isupper(key_char) ? 'A' : 'a';
        int ciphertext_val = ciphertext_char - base_ciphertext;
        int key_val = key_char - base_key;
        int plaintext_val = (key_val - ciphertext_val + 26) % 26;
        return (char)(plaintext_val + base_ciphertext);
    }
    return ciphertext_char;
}

void decrypt_beaufort(char *ciphertext, char *plaintext, char *key) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = decrypt_beaufort_char(ciphertext[i], key[i % key_len]);
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

    printf("Enter the key (alphabetic): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    encrypt_beaufort(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted_plaintext[100];
    decrypt_beaufort(ciphertext, decrypted_plaintext, key);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}