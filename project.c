#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 1000

/*Using C program, randomly generate a directed graph represented by adjacency matrix with
n = 1000 vertices. */

int dG[n][n];

int main()
{
    int i, j, rnum;

    srand(time(0));


    for(i=0; i<n; i++) {

        for(j=0; j<n; j++) {

            rnum = rand() % 2;

            dG[i][j] = rnum;
        }
    }


/*Determine in-degrees and out-degrees of all vertices and show that sum of in-degrees and
sum of out-degrees are equal. Determine computational time in this step (except printing
time) in ns. */

    double computational_time_ns = 0.0;

    clock_t begin = clock();

    int indeg = 0, outdeg = 0;

    for(i=0; i<n; i++) {

        for(j=0; j<n; j++) {

            if(dG[i][j] == 1) {
                outdeg++;
            }

            if(dG[j][i] == 1) {
                indeg++;
            }
        }
    }

    printf("Sum of in-degrees = %d\nsum of out-degrees = %d\n",indeg,outdeg);

    if(indeg == outdeg) {
        printf("\nSum of in-degrees and Sum of out-degrees are equal\n");
    }

    clock_t end = clock();

    computational_time_ns = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000000000 ;

    return 0;
}

