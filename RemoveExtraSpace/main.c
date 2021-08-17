//remove extra spaces from a source code in c

#include <stdio.h>

int main() {
 FILE *finput, *foutput;
 char ch;
 finput = fopen("input.txt", "r");
 foutput = fopen("output.txt", "w");
 if(finput == NULL)
 printf("Error in opening file...");
 while((ch = fgetc(finput)) != EOF) {
 if(ch == ' ') {
 putc(ch, foutput);
 for (int i = 0; (ch = fgetc(finput)) == ' '; i++);
 }
 putc(ch, foutput);
 }
 fclose(finput);
 fclose(foutput);
 return 0;
 
}
