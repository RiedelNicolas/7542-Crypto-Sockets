#include <stdio.h>
#include "common_FileReader.h"

int main(){
    size_t tope = 64;
    char mensaje [65];
    mensaje[64] = NULL;

    FileReader lector;
    fileReaderStandardInit(&lector);
    printf("se inicio correctamente");
    size_t leidos = fileReaderRead(&lector, mensaje, tope);
    printf("llego abajo");
    fileReaderUninit(&lector);
    printf("%zu",leidos);
    return 0;
}
