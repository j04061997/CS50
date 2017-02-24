 #include <stdio.h>
#include <cs50.h>

int validate(long long int card);

int main(void) {
    long long int card;
    do {
        printf("Card number: ");
        card = get_long_long();
    }while(card < 0);
    validate(card);
}
int validate(long long int card) {
    char flag;
    int lenght;
    // v = VISA, a = AMEX, m = MASTERCARD
    if(card >= 4000000000000 && card <= 4999999999999) {
        lenght = 13;
        flag = 'v';
    } else if((card >= 340000000000000 && card <= 349999999999999) || (card >= 370000000000000 && card <= 379999999999999)) {
        lenght = 15;
        flag = 'a';
    } else if(card >= 5100000000000000 && card <= 5599999999999999) {
        lenght = 16;
        flag = 'm';
    } else if(card >= 4000000000000000 && card <= 4999999999999999) {
        lenght = 16;
        flag = 'v';
    } else {
        printf("INVALID\n");
        return 1;
    }
    long long int divisor = 1;
    int sum = 0, digit;
    for(int counter = 0; counter < lenght; counter++, divisor *= 10) {
        digit = (card/divisor)%10;
        if(digit != 0){
            if(counter == 0 || counter%2 == 0) {
                sum += digit;
            } else {
                digit *= 2;
                if(digit >= 10) {
                    sum += ((digit/10) + (digit%10));
                } else {
                    sum += digit;
                }
            }
        }
    }
    if(sum%10 == 0) {
        if(flag == 'a')
            printf("AMEX\n");
        else if(flag == 'm')
            printf("MASTERCARD\n");
        else if(flag == 'v')
            printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
    return 0;
}
