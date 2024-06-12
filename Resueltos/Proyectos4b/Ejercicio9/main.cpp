#include <stdio.h>

struct EstructuraVacia {};

int main() {
    struct EstructuraVacia ev;
    printf("El tamaño de una estructura vacía en C es: %zu bytes.\n", sizeof(struct EstructuraVacia));
    return 0;
}