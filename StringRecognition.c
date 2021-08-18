//Program to recognize a string under the regular expression ab(a|b)*abb

#include <stdio.h>
#include <stdbool.h>

#define END_STATE 'X'

int main() {

    char str[50];
    char state = 'A'; //A as initial state
    bool endStateReached = false;

    printf("Enter the string:\n");
    gets(str);

    int i = -1;
    while(str[++i] != '\0' && !endStateReached) {

        switch (state) {

            case 'A':
                if(str[i] == 'a') state = 'B';
                else state = END_STATE;
                break;
            case 'B':
                if(str[i] == 'b') state = 'C';
                else state = END_STATE;
                break;
            case 'C':
                if(str[i] == 'a') state = 'D';
                else if(str[i] == 'b') state = 'E';
                else state = END_STATE;
                break;
            case 'D':
                if(str[i] == 'a') state = 'D';
                else if(str[i] == 'b') state = 'F';
                else state = END_STATE;
                break;
            case 'E':
                if(str[i] == 'a') state = 'D';
                else if(str[i] == 'b') state = 'E';
                else state = END_STATE;
                break;
            case 'F':
                if(str[i] == 'a') state = 'D';
                else if(str[i] == 'b') state = 'G';
                else state = END_STATE;
                break;
            case 'G':
                if(str[i] == 'a') state = 'D';
                else if(str[i] == 'b') state = 'E';
                else state = END_STATE;
                break;
            default: //if end state occurs
                endStateReached = true;
                break;
        }
    }

    printf("%s", (state == 'G') ? "Accepted" : "Rejected");

    return 0;
}
