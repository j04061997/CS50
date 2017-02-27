#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    string name = get_string();
    
    for(int counter = 0, length = strlen(name), condition = 0; counter < length; counter++) {
        if(name[counter] != ' ') {
            if(condition == 0) {
                printf("%c", toupper(name[counter]));
                condition = 1;
            } else if(name[counter+1] == ' ')
                condition = 0;
        }
    }
    printf("\n");
}
