#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 //Imprimir a y b con 8 hilos

void *funcion(void *ap) {
    struct data *x;
    x = ap;
    printf("a: %i, b: %i", x->a, x->b);|
}


struct data{
    int a;
    int b;
};

int main(){

    pthread_t thread[8];
    struct data arg[8]; //falta for para llenar datos de lo contrario, SALE MAL.
    void **retval;

    for(int i=0; i<8; i++)
    {
        int r = pthread_create(&thread[i], NULL, funcion, (void*) &arg[i]);
        if(r != 0)
        {
            perror("Salio mal");
            exit(-1);
        }
    }

    for(int i=0; i < 8; i++)
    {
        pthread_join(thread[i], retval);
    }
    return 0;
}
