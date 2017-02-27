 #include <stdio.h>
#include <cs50.h>
#include <string.h>
int calc(int key, int letter);

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./caesar k");
        return 1;
    }
    printf("plaintext: ");
    string plain = get_string();
    int key = atoi(argv[1])%26;
    int length = strlen(plain);
    char cipher[length];
    for(int counter = 0; counter < length; counter++) {
        if((plain[counter] > 64 && plain[counter] < 91) || (plain[counter] > 96 && plain[counter] < 123)) {
            if((plain[counter] + key) > 90 || (plain[counter] + key) > 122)
                cipher[counter] = plain[counter] + calc(key, plain[counter]);
            else
                cipher[counter] = plain[counter] + key;
        } else
            cipher[counter] = plain[counter];
    }
    printf("ciphertext: %s\n", cipher);
}
int calc(int key, int letter) {
    for(;;) {
        if(letter < 91) {
            if((letter + key) > 90)
                key -= 26;
            else
                return key;
        } else {
            if((letter + key) > 122)
                key -= 26;
            else
                return key;
        }
    }
}
