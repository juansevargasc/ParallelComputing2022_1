#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#define ITERATIONS 1e9


double calculate_pi()
{
    double result = 0;

    // Portion of pi calculation
    for (int i = 0; i < ITERATIONS; i++)
    {
        /* code */
        
        int positive = ( (4 * i) + 1);
        int negative = positive + 2;

        result += (double) 4 / positive;
        result -= (double) 4 / negative;
    }

    return result;
    
}

int main()
{
    //TIME
    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);

    // Calculation
    double r = calculate_pi();
    printf("PI: %2.12f", r);

     // TIME
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);
    printf("\nTime elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    return 0;
}
