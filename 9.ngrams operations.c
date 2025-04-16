#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char *ngram;
    int count;
} NgramFrequency;

int compareNgrams(const void *a, const void *b) {
    return strcmp(((NgramFrequency *)a)->ngram, ((NgramFrequency *)b)->ngram);
}

void generate_ngrams(const char *text, int n) {
    int len = strlen(text);
    if (n > len || n <= 0) {
        return;
    }
    for (int i = 0; i <= len - n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", text[i + j]);
        }
        printf("\n");
    }
}

void count_ngram_frequencies(const char *text, int n) {
    int len = strlen(text);
    if (n > len || n <= 0) {
        return;
    }
    int max_ngrams = len - n + 1;
    NgramFrequency *frequencies = malloc(max_ngrams * sizeof(NgramFrequency));
    int num_ngrams = 0;

    for (int i = 0; i <= len - n; i++) {
        char *ngram = malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) {
            ngram[j] = tolower(text[i + j]);
        }
        ngram[n] = '\0';

        int found = 0;
        for (int k = 0; k < num_ngrams; k++) {
            if (strcmp(frequencies[k].ngram, ngram) == 0) {
                frequencies[k].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            frequencies[num_ngrams].ngram = ngram;
            frequencies[num_ngrams].count = 1;
            num_ngrams++;
        }
    }

    qsort(frequencies, num_ngrams, sizeof(NgramFrequency), compareNgrams);

    for (int i = 0; i < num_ngrams; i++) {
        printf("%s: %d\n", frequencies[i].ngram, frequencies[i].count);
        free(frequencies[i].ngram);
    }
    free(frequencies);
}

int main() {
    char text[200];
    int n;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    printf("Enter the ngram size (n): ");
    scanf("%d", &n);
    while (getchar() != '\n');

    printf("\nGenerated Ngrams:\n");
    generate_ngrams(text, n);

    printf("\nNgram Frequencies:\n");
    count_ngram_frequencies(text, n);

    return 0;
}