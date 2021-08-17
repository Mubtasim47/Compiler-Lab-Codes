//removal of extra white spaces considering both '\t' and ' '

#include <stdio.h>
FILE *finput, *foutput;
int main() {
 char ch;
 finput = fopen("input.txt", "r");
 foutput = fopen("output.txt", "w");
 if(finput == NULL) {
 printf("Error in opening file...");
 return 0;
 }
 while((ch = fgetc(finput)) != EOF) {
 if(ch == ' ' || ch == '\t') {
 fputc(' ', foutput);
 /*while loop checks for any other occurrence
 of space or tab until a valid character is found*/
 while(ch == ' ' || ch == '\t') {
 ch = fgetc(finput);
 }
 }
 fputc(ch, foutput);
 }
 fclose(finput);
 fclose(foutput);
 return 0;
  
}
//input contains spaces both using TAB and Space bar
