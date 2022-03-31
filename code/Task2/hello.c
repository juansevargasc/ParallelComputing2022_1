// clang -Xpreprocessor -fopenmp -I/usr/local/include -L/usr/local/lib -lomp  main.c -o main
/// opt/homebrew/opt/llvm/bin/clang $LDFLAGS -fopenmp Task2/hello.c -o hello -lomp
#include "omp.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    #pragma omp parallel //inicio de region paralela 5
    {
        int ID = omp_get_thread_num(); 
        printf("Hello( %d)", ID); 
        printf(" world( %d) \n", ID);
    } //fin de region paralela

}

