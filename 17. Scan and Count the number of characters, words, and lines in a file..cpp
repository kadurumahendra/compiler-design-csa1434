#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    int characterCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        characterCount++;

        if (c == '\n') {
            lineCount++;
            inWord = 0; // Reset inWord flag when a new line is encountered
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            wordCount++;
        }
    }

    fclose(file);

    // Check if the last word is not followed by a space or newline
    if (inWord == 1) {
        wordCount++;
    }

    printf("Number of characters: %d\n", characterCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}

