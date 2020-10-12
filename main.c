#include <stdio.h>
#include "common_file_reader.h"

int main(){
    size_t tope = 64;
    char mensaje [65];
    mensaje[64] = NULL;

    file_reader_t lector;
    file_reader_standard_init(&lector);
    printf("se inicio correctamente");
    size_t leidos = file_reader_read(&lector,mensaje, tope );
    printf("llego abajo");
    file_reader_uninit(&lector);
    printf("%zu",leidos);
    return 0;
}
