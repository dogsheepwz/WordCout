#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

int countWords(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int count = 0;
    int inWord = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (inWord) {
                count++;
                inWord = 0;
            }
        }
        else {
            inWord = 1;
        }
    }
if (inWord) count++; // Handle last word if it doesn't end with whitespace
fclose(file);
return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s -c|-w filename\n", argv[0]);
        return 1;
    }

    const char* parameter = argv[1];
    const char* filename = argv[2];

    if (strcmp(parameter, "-c") == 0) {
        int characters = countCharacters(filename);
        printf("Characters: %d\n", characters);
    }
    else if (strcmp(parameter, "-w") == 0) {
        int words = countWords(filename);
        printf("Words: %d\n", words);
    }
    else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    return 0;
}