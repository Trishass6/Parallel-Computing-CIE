/* Write an OpenMp program to transform each element with A[i]=3*A[i]+2 using #pragma omp parallel for schedule(dynamic,2) then switch to (static,2) 
consider array int A1[6]={1,2,3,4,5,6}; -> dynamic,2 
               int A2[6]={1,2,3,4,5,6}; -> static,2  */



#include <stdio.h>
#include <omp.h>

int main() {
   
    int A1[6] = {1, 2, 3, 4, 5, 6};
    int A2[6] = {1, 2, 3, 4, 5, 6};

    printf("Using dynamic scheduling with chunk size of 2:\n");
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 6; i++) {
        A1[i] = 3 * A1[i] + 2;
    }

    for (int i = 0; i < 6; i++) {
        printf("A1[%d] = %d\n", i, A1[i]);
    }

    printf("\nUsing static scheduling with chunk size of 2:\n");
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
    }

    for (int i = 0; i < 6; i++) {
        printf("A2[%d] = %d\n", i, A2[i]);
    }

    return 0;
}
