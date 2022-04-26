#include <stdio.h>


int main() {
    float aux, s, t;
    s = 0;
    for (t=1; t < 11; t++)
    {
     aux = 1/t;
     s = s + aux;
    }
    printf("O valor de S é: %f", s);
}



