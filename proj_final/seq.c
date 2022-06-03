#include <stdio.h>


int main() {
    float s, t;
    s = 0;
    for (t=1; t < 11; t++)
    {
     s = s + 1/t;
    }
    printf("O valor de S é: %f", s);
}
