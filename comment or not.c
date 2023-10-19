#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isComment(const char *line) {
    // Check if the line starts with "//" (single-line comment)
    if (strncmp(line, "//", 2) == 0) {
        return true;
    }
    
    // Check if the line starts with "/*" and ends with "*/" (multi-line comment)
    if (strncmp(line, "/*", 2) == 0 && strstr(line, "*/") != NULL) {
        return true;
    }
    
    return false;
}

int main() {
    char line[256];
    
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);
    
    if (isComment(line)) {
        printf("The entered line is a comment.\n");
    } else {
        printf("The entered line is not a comment.\n");
    }
    
    return 0;
}
