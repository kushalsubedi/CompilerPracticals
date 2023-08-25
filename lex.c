#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum {
    KEYWORD,
    SEPARATOR,
    IDENTIFIER,
    OPERATOR,
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

bool isSeparator(char c) {
    char separators[] = "{}()[];,";
    for (int i = 0; i < strlen(separators); i++) {
        if (separators[i] == c) {
            return true;
        }
    }
    return false;
}

bool isOperator(char c) {
    char operators[] = "+-*=";
    for (int i = 0; i < strlen(operators); i++) {
        if (operators[i] == c) {
            return true;
        }
    }
    return false;
}

bool isKeyword(char *token) {
    char keywords[][10] = {
         "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "inline", "int", "long", "register", "restrict", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
    };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

void analyzeLexically(FILE *file) {
    Token token;
    char buffer[1000];
    int bufferIndex = 0;
    char c;
    
    while ((c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0'; // Null-terminate the buffer
                if (isKeyword(buffer)) {
                    token.type = KEYWORD;
                    strcpy(token.value, buffer);
                    printf("KEYWORDS : %s\n", token.value);
                } else {
                    token.type = IDENTIFIER;
                    strcpy(token.value, buffer);
                    printf("IDENTIFIERS : %s\n", token.value);
                }
                bufferIndex = 0; // Reset buffer
            }
            continue;
        }
        if (isSeparator(c)) {
            token.type = SEPARATOR;
            token.value[0] = c;
            token.value[1] = '\0';
            printf("SEPARATORS : %s\n", token.value);
        } else if (isOperator(c)) {
            token.type = OPERATOR;
            token.value[0] = c;
            token.value[1] = '\0';
            printf("OPERATORS : %s\n", token.value);
        } else {
            buffer[bufferIndex++] = c;
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("ENTER THE FILENAME : ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("FAILED TO OPEN A FILE .... \n");
        return 1;
    }
    printf("PERFORMING LEXICAL analysis .... \n");
    analyzeLexically(file);
    fclose(file);
    return 0;
}

