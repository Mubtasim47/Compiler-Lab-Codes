//Remove line comment(s) from a source code

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



void remove_comment (char ch) {
    char d;
    if(ch == '/') {
        d = ch;
        ch = (char) fgetc(fpi);
        if(ch == '/') {
            while((ch = (char) fgetc(fpi)) !='\n');
            fputc(ch, fpo);
            return;
        }
        fputc(d, fpo);
        fputc(ch, fpo);
        return;

    }
    fputc(ch, fpo);

}
