#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "omp.h"

#define NUM_THREADS 1
#define ITERATIONS 1e09


double piTotal[NUM_THREADS];


int calculate_pi(int id)
{
    printf("THREAD #%d now running!\n", id);

    int portion = (ITERATIONS/NUM_THREADS);
    int begin = id * portion;
    int end = (begin + portion);


    // Portion of pi calculation
    for (int i = begin; i < end; i++)
    {
        /* code */
        //printf("Test with id: %i\n", id);
        int positive = ( (4 * i) + 1);
        int negative = positive + 2;

        *(piTotal + id) += (double) 4 / positive;
        *(piTotal + id) -= (double) 4 / negative;
    }

    return 0;
    
}

int main()
{
    //TIME
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);

    // Variables
    int threads = NUM_THREADS;

    // Llenar región de memoria
    for (int i = 0; i < threads; i++)
    {
        *(piTotal + i ) = 0;
    }
    

    // Thread creation.
    #pragma omp parallel num_threads(threads)
    {
        int ID = omp_get_thread_num(); 
        calculate_pi(ID);
    }
    
    double* res;
    double q = 0;
    res = &q;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        /* code */
        *res += *(piTotal + i);
    }
    
    
    printf("PI: %2.12f", *res);
    /* Last thing that main() should do */

    // RESULTS
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("\nTime elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
    

    return 0;
}
