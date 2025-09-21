#include <stdio.h>
#include <ctype.h>  

#define ALPHABET_SIZE 26  

void count_letters(const char *str) {
    int count[ALPHABET_SIZE] = {0}; 

    while (*str != '\0') {
       
        char ch = tolower(*str);

      
        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++;  
        }

        str++;  
    }

    printf("letter count:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count[i] > 0) {
            printf("We can see the letter '%c', times: %d \n", i + 'a', count[i]);
        }
    }
}

int main() {
    const char *str = "Hello world!";

    count_letters(str);  

    return 0;
}
