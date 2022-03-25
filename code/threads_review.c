#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 8
 //Imprimir a y b con 8 hilos

struct data
{
    int a;
    int b;
};

void *funcion(void *ap) 
{
    struct data *x;
    x = ap;
    printf("a: %i, b: %i\n", x -> a, x -> b); // -> es la forma de extraer los parámetros usando un apuntador

    return 0;
}


int main()
{
    // Variables
    pthread_t thread[8];
    struct data arg[8]; 
    int** retval;

    for (int i = 0; i < NUM_THREADS; i++)
    {   
        
        arg[i].a = i + 1; // # of thread
        arg[i].b = i + 2;
    }
    

    for(int i = 0; i < NUM_THREADS; i++)
    {
        int r = pthread_create(&thread[i], NULL, funcion, (void*) &arg[i]);
        if(r != 0)
        {
            perror("Salio mal");
            exit(-1);
        }
    }

    for(int i=0; i < NUM_THREADS; i++)
    {
        pthread_join(thread[i], (void **) retval);
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
    return 0;
}
