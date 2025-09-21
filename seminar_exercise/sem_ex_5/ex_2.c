#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LEN 51
#define MAX_INPUT_WORDS 100

int matches_condition(const char *prev, const char *current) {
    if (!prev || !current || strlen(prev) == 0 || strlen(current) == 0)
        return 0;
    char last = tolower(prev[strlen(prev) - 1]);
    char first = tolower(current[0]);
    return last == first;
}

void create_input_file() {
    FILE *input = fopen("input.txt", "w");
    if (!input) {
        perror("Failed to create input.txt");
        exit(1);
    }

    int num_words;
    printf("How many words do you want to enter? ");
    scanf("%d", &num_words);
    getchar();

    char word[MAX_WORD_LEN];
    printf("Enter %d word(s):\n", num_words);
    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        fgets(word, MAX_WORD_LEN, stdin);


        word[strcspn(word, "\n")] = '\0';

        fprintf(input, "%s", word);
        if (i < num_words - 1) {
            fputc(' ', input);
        }
    }

    fclose(input);
    printf("File input.txt created successfully!\n\n");
}

int main() {

    create_input_file();


    FILE *input = fopen("input.txt", "r");
    if (!input) {
        perror("Failed to open input.txt");
        return 1;
    }

    char word[MAX_WORD_LEN];
    char **filtered_words = NULL;
    int count = 0;
    char previous_word[MAX_WORD_LEN] = {0};

    while (fscanf(input, "%50s", word) == 1) {
        if (count == 0 || matches_condition(previous_word, word)) {
            filtered_words = realloc(filtered_words, (count + 1) * sizeof(char *));
            if (!filtered_words) {
                perror("Memory allocation failed");
                fclose(input);
                return 1;
            }
            filtered_words[count] = strdup(word);
            if (!filtered_words[count]) {
                perror("Failed to duplicate word");
                fclose(input);
                return 1;
            }
            strcpy(previous_word, word);
            count++;
        }
    }
    fclose(input);

    FILE *output = fopen("output.bin", "wb");
    if (!output) {
        perror("Failed to open output.bin");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fwrite(filtered_words[i], sizeof(char), strlen(filtered_words[i]), output);
        if (i < count - 1) {
            fputc(' ', output);
        }
    }
    fclose(output);


    for (int i = 0; i < count; i++) {
        free(filtered_words[i]);
    }
    free(filtered_words);

    output = fopen("output.bin", "rb");
    if (!output) {
        perror("Failed to open output.bin for reading");
        return 1;
    }

    printf("\nContents of output.bin:\n");
    int ch;
    while ((ch = fgetc(output)) != EOF) {
        putchar(ch);
    }
    putchar('\n');
    fclose(output);

    return 0;
}

