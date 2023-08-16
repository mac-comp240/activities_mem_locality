#include <stdio.h>
#include <stdlib.h>
#include "timing.h"

#define N 1<<16


int sum_recur(int *v, int pos, int length) {
    if (pos == length) {
        return 0;
    }
    else {
        return v[pos] + sum_recur(v, pos+1, length);
    }
}

/*
 * Stride-1 sum of all elements in the array V.
 */
int sumvec(int * v, int length) {  	
    int i, sum = 0; 

    for (i = 0; i < length; i++) {
        sum += v[i];
    }
    return sum;	
}


int main(int argc, char *argv[]) {
    // one argument for the size of stride to try
    int array_length = N;   // default if nothing entered on command line
    
    // argc is the total number of arguments, including the invoking of the program
    // argv[] is an array of strings
    // argv[0] always has the name of the program
    // argv[1] has the first argument typed
    //
    
    if (argc >1) {
        array_length = atoi(argv[1]);  // 
    }
        
    printf("For program %s, array length is set to %d\n", argv[0], array_length);
    
    // array to use. 
    // Note that we did not use malloc here- you could change it to do so for practice
    int vector[array_length];      // vector array to hold data values

    // other variables
    int i;
    int sum = 0;
        
    //////////////  need for timing code
    wallclock_t  t;       // from "timing.h", holds time data
    double  s;            // seconds
    ///////////////////////

    // initialize our vector of data, vector
    for (i = 0; i < array_length; i++) {
        vector[i] = ((i%2 == 0) ? 1 : -1);
    }

//     /*
    wallclock_mark(&t);       // start timing
    sum = sumvec(vector, array_length);
    s = wallclock_since(&t);  // finish timing
    
    //should sum to zero 
    printf("sumvec: sum=%d\n", sum);
    printf("That took %.9f seconds wall clock time.\n", s);
//     */

//     /*
    wallclock_mark(&t);       // start timing
    sum = sum_recur(vector, 0, array_length);
    s = wallclock_since(&t);  // finish timing
    
    //should sum to zero 
    printf("sum_recur: sum=%d\n", sum);
    printf("That took %.9f seconds wall clock time.\n", s);
//     */
    return 0;
}
