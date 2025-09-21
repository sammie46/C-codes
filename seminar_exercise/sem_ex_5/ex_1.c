#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define MAX_ATTEMPTS(word_len) ((word_len) + 2)
#define MAX_WORD_LENGTH 100

void printWordState(const char word[], const int guessed[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[i]) {
            printf("%c", word[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int isWordGuessed(const int guessed[], int length) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) return 0;
    }
    return 1;
}

void getHiddenInput(char *word) {
    char ch;
    int i = 0;

    printf("Enter the word to guess (input will be hidden): ");

    while (i < MAX_WORD_LENGTH - 1) {
        ch = getch();

        if (ch == '\r') break;

        if (isalpha(ch)) {
            word[i++] = tolower(ch);
            printf("*");
        }
    }
    word[i] = '\0';
    printf("\n");
}

int main() {
    char word[MAX_WORD_LENGTH];
    getHiddenInput(word);

    int wordLen = strlen(word);
    int guessedLetters[wordLen];
    int attempts = 0;
    char guess;

    for (int i = 0; i < wordLen; i++) {
        guessedLetters[i] = 0;
    }

    printf("\nLet the guessing begin!\n");
    printf("The word has %d letters.\n", wordLen);

    while (attempts < MAX_ATTEMPTS(wordLen)) {
        printf("Current word state: ");
        printWordState(word, guessedLetters);

        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (!isalpha(guess)) {
            printf("Please enter a valid letter!\n");
            continue;
        }

        int correct = 0;
        for (int i = 0; i < wordLen; i++) {
            if (word[i] == guess && !guessedLetters[i]) {
                guessedLetters[i] = 1;
                correct = 1;
            }
        }

        attempts++;

        if (correct) {
            printf("Correct guess!\n");
        } else {
            printf("Wrong guess.\n");
        }

        if (isWordGuessed(guessedLetters, wordLen)) {
            printf("Congratulations! You guessed the word: %s\n", word);
            printf("Total guesses: %d (allowed: %d)\n", attempts, MAX_ATTEMPTS(wordLen));
            return 0;
        }
    }

    printf("Sorry! You've exceeded the maximum number of attempts (%d).\n", MAX_ATTEMPTS(wordLen));
    printf("The correct word was: %s\n", word);

    return 0;
}
