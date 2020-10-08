#include <stdio.h>
#include "encriptador.h"

int main() {

    char mensaje [1024];
    int des;

    printf("ingrese un mensaje\n");
    scanf("%s",mensaje);
    printf("ingrese desplazamiento \n");
    scanf("%i",&des);
    cifrado_cesar(mensaje,des);
    printf("%s",mensaje);
    return 0;
}
