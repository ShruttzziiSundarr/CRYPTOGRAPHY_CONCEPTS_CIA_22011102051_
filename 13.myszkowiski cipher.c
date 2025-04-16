#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int get_column_order(const char *key, int *order) {
    int key_len = strlen(key);
    char indexed_key[key_len];
    for (int i = 0; i < key_len; i++) {
        indexed_key[i] = key[i];
    }
    int sorted_indices[key_len];
    for (int i = 0; i < key_len; i++) {
        sorted_indices[i] = i;
    }

    for (int i = 0; i < key_len - 1; i++) {
        for (int j = i + 1; j < key_len; j++) {
            if (indexed_key[sorted_indices[i]] > indexed_key[sorted_indices[j]]) {
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }

    for (int i = 0; i < key_len; i++) {
        order[sorted_indices[i]] = i;
    }
    return key_len;
}

void encryptMyszkowski(char *plaintext, char *key, char *ciphertext) {
    int key_len = strlen(key);
    int pt_len = strlen(plaintext);
    int rows = (pt_len + key_len - 1) / key_len;
    char grid[rows][key_len];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            grid[i][j] = '\0';
        }
    }

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len && k < pt_len; j++) {
            grid[i][j] = plaintext[k++];
        }
    }

    int order[key_len];
    get_column_order(key, order);

    int ct_index = 0;
    for (int i = 0; i < key_len; i++) {
        for (int j = 0; j < rows; j++) {
            if (grid[j][order[i]] != '\0') {
                ciphertext[ct_index++] = grid[j][order[i]];
            }
        }
    }
    ciphertext[ct_index] = '\0';
}

void decryptMyszkowski(char *ciphertext, char *key, char *plaintext) {
    int key_len = strlen(key);
    int ct_len = strlen(ciphertext);
    int rows = (ct_len + key_len - 1) / key_len;
    char grid[rows][key_len];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            grid[i][j] = '\0';
        }
    }

    int order[key_len];
    get_column_order(key, order);

    int ct_index = 0;
    for (int i = 0; i < key_len; i++) {
        for (int j = 0; j < rows; j++) {
            if (ct_index < ct_len) {
                grid[j][order[i]] = ciphertext[ct_index++];
            }
        }
    }

    int pt_index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            if (grid[i][j] != '\0') {
                plaintext[pt_index++] = grid[i][j];
            }
        }
    }
    plaintext[pt_index] = '\0';
}

int main() {
    char plaintext[200];
    char key[20];
    char ciphertext[200];
    char decryptedText[200];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    encryptMyszkowski(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decryptMyszkowski(ciphertext, key, decryptedText);
    printf("Decrypted plaintext: %s\n", decryptedText);

    return 0;
}