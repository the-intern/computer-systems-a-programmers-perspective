#include <stdio.h>

#include "helper.h"
void converter() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("F\t\tC\n");
    printf("----\t\t-----\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t|\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}