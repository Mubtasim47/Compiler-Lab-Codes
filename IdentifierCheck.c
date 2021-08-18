#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAlphabet(char);
bool isNumber(char);

bool isAlphabet(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isNumber(char ch) {
    return (ch >= '0' && ch <= '9');
}


int main() {

    char str[50];


    printf("Enter a string:\n");
    gets(str);

    char keyword[32][10] = {
            "auto", "double", "int", "struct", "break", "else", "long",
            "switch", "case", "enum", "register", "typedef", "char",
            "extern", "return", "union", "const", "float", "short",
            "unsigned", "continue", "for", "signed", "void", "default",
            "goto", "sizeof", "volatile", "do", "if", "static", "while"
    };


    for (int i = 0; i < 32; i++) {
        if (!strcmp(str, keyword[i])) {
            printf("Valid keyword\n");
            return 0;
        }
    }

    bool $validIdentifier = false;

    if (isAlphabet(str[0]) || str[0] == '_' || str[0] == '$') {
        $validIdentifier = true;
        int i = 0;
        while (str[i] != '\0') {
            if (isAlphabet(str[i]) || isNumber(str[i]) || str[i] == '_' || str[i] == '$') {
                i++;
                continue;
            } else {
                $validIdentifier = false;
                break;
            }

        }
    }

    printf("%s %s", $validIdentifier ? "Valid" : "Not a valid", "identifier");

    return 0;
}
