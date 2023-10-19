#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a keyword
bool isKeyword(const char *word) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
        "long", "register", "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; ++i) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to classify a token
void classifyToken(const char *token) {
    if (isKeyword(token)) {
        printf("Keyword: %s\n", token);
    } else if (isalpha(token[0])) {
        printf("Identifier: %s\n", token);
    } else if (isdigit(token[0])) {
        printf("Constant: %s\n", token);
    } else {
        printf("Operator or Symbol: %s\n", token);
    }
}

int main() {
    char expression[256];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    const char delimiters[] = " \t\n(){}[],;+-*/%=<>&|!";
    char *token = strtok(expression, delimiters);

    while (token != NULL) {
        classifyToken(token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}
