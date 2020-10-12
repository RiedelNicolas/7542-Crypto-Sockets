#include <stdio.h>
#include "file_reader.h"

int main(){
    size_t tope = 50;
    char mensaje [50];
    file_reader_t lector;
    file_reader_standard_init(&lector);
    printf("se inicio correctamente");
    size_t leidos = file_reader_read(&lector,mensaje, tope );
    printf("llego abajo");
    file_reader_uninit(&lector);
    printf("%zu",leidos);
    return 0;
}
