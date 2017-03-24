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
    for(int row = 0; line < height; row++) {
        space(num_space);
        num_space--;
        hash(row);
        space(2);
        hash(row);
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
