//C program to remove both block and line comment from a source file

#include <stdio.h>

void remove_comment(char);

FILE *fpi, *fpo;

int main() {
    char c;
    fpi = fopen("input.txt", "r");
    fpo = fopen("output.txt", "w");
    while((c = (char) fgetc(fpi)) != EOF)
        remove_comment(c);
    fclose(fpi);
    fclose(fpo);
    return 0;
}


void remove_comment(char ch) {
    char d;
    if(ch == '/') {
        d = ch;
        ch = (char) fgetc(fpi);
        if(ch == '/') {
            while((ch = (char)fgetc(fpi)) != '\n');
            fputc(ch, fpo);
            return;
        } else if(ch == '*') {
            while(fgetc(fpi) != '*');
            ch = (char) fgetc(fpi);
            if(ch == '/') {
                ch = (char) fgetc(fpi);
                fputc(ch, fpo);
                return;
            }
        } else
        {
            fputc(d, fpo);
            fputc(ch, fpo);
            return;

        }

    }
    fputc(ch, fpo);
}
