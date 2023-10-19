include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to remove leading and trailing whitespace from a string
void trimWhitespace(char *str) {
    int start = 0, end = strlen(str) - 1;
    
    while (str[start] != '\0' && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }
    
    while (end > start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }
    
    str[end + 1] = '\0';
    
    if (end > start) {
        memmove(str, str + start, end - start + 2);
    } else {
        str[0] = '\0';
    }
}

// Function to remove single-line comments from a string
void removeComments(char *str) {
    char *commentStart = strstr(str, "//");
    if (commentStart != NULL) {
        *commentStart = '\0';
    }
}

int main() {
    char line[256];

    printf("Enter lines of code (Ctrl+Z or Ctrl+D to exit):\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        trimWhitespace(line);
        removeComments(line);

        if (line[0] != '\0') {
            printf("Processed line: %s\n", line);
        }
    }

    return 0;
}
