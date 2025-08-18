//Write an OpenMp program which launches a parallel region and it has each thread print its id and team size.


#include <stdio.h>
#include <omp.h>

int main() {
   
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();     
        int num_threads = omp_get_num_threads();  
        printf("Hello from thread %d out of %d threads\n", thread_id, num_threads);
    }

    return 0;
}
