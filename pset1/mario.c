#include <stdio.h>
#include <cs50.h>
//MORE CONFORTABLE VERSION
void space(int repeat);
void hash(int repeat);
int main(void) {
    int height;
    do {
        printf("Height: ");
        height = get_int();
    } while ((height > 23) || (height < 0));
    int num_space = height - 1;
    for(int line = 0; line < height; line++) {
        space(num_space);
        num_space--;
        hash(line);
        space(2);
        hash(line);
        printf("\n");
    }
}
void space(int repeat) {
    for(int counter = 0; counter < repeat; counter++)
        printf(" ");
}
void hash(int repeat) {
    for(int counter = 0; counter <= repeat; counter++)
        printf("#");
}
