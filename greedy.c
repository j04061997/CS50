#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    printf("O hai! ");
    float dolars;
    do {
        printf("How much change is owed?\n");
        dolars = get_float();
    } while(dolars < 0.00);
    int coins = dolars*100 + 0.1;
    int change = 0;
    do {
        if(coins/25 >= 1)
            coins -= 25;
        else if(coins/10 >= 1)
            coins -= 10;
        else if(coins/5 >= 1)
            coins -= 5;
        else
            coins -= 1;
        change++;
    } while(coins > 0);
    printf("%i\n", change);
}
