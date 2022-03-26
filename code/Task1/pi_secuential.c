#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 2
#define ITERATIONS 10e5

double piTotal[NUM_THREADS];

void *calculate_pi(void* ap)
{
    
    int id;
    id = (int) ap;
    printf("THREAD #%d now running!", id);

    int portion = (ITERATIONS/NUM_THREADS);
    int begin = id * portion;
    int end = (begin + portion);

    double result = 0;

    // Portion of pi calculation
    for (int i = begin; i < end; i++)
    {
        /* code */
        //printf("Test with id: %i\n", id);
        int positive = ( (4 * i) + 1);
        int negative = positive + 2;

        result += 4 / positive;
        result -= 4 / negative;
    }

    // Saving in global variable
    piTotal[id] = result;

    return 0;
    
}

int main()
{
    // Variables
    pthread_t thread[4];
    int thread_ID[4]; 
    int** retval;
    double pi = 0;

    // Indicate id number for each thread.
    for (int i = 0; i < NUM_THREADS; i++)
    {   
        thread_ID[i] = i;
    }
    
    // Thread creation.
    for(int i = 0; i < NUM_THREADS; i++)
    {
        int r = pthread_create(&thread[i], NULL, calculate_pi, (void*) thread_ID[i]);
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

    double res = 0;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        /* code */
        res += piTotal[i];
    }
    
    printf("PI: %f", res);
    /* Last thing that main() should do */
    pthread_exit(NULL);

    return 0;
}
