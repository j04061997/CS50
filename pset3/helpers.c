/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
#include "helpers.h"
#include <cs50.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n) {
    int left = 0, middle, right = n, counter=0;
    for(;;) {
        if(counter == 0) {
            if(value == values[right] || value == values[left])
                return true;
        }
        middle = (left + right)/2;
        if(value > values[middle])
            left = middle;
        else if(value < values[middle])
            right = middle;
        else if(value == values[middle])
            return true;
        if(left+1 == n)
            return false;
        counter++;
    }
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    for(int counter=0, temporary, higher=0; counter < n; counter++) {
        if(values[counter] > values[counter+1]) {
            temporary = values[counter+1];
            values[counter+1] = values[counter];
            values[counter] = temporary;
        }
        if(values[counter] > higher)
            higher = values[counter];
        if(counter == n-1) { 
            if(values[n-1] > higher) {
                n--;
                higher = 0;
            }
        }
    }
}
