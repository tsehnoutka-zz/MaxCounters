#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Results {
  int * C;
  int L; // Length of the array
};

struct Results solution(int N, int A[], int M)
{
    int i=0;
    int max=0;
    struct Results* myResults=(struct Results*)malloc(sizeof(struct Results));
    int arraySize = sizeof(int)*M;
    myResults.C = (int*)malloc(arraySize);
    myResults.L = M;

    
    for (i=0; i<M; i++){
        if (A[i] == N+1){
            memset(myResults.C,max,arraySize);
        }
        else
        {
            int temp = (myResults.C + A[i])+1;
            if (temp > max )
                max = temp;
        }
       
    }
    return myResults;
}


/*
 * 
 */
int main(int argc, char** argv) {
    int N=5;
    int[] A = [3,4,4,6,1,4,4];
    int M = 7;
    int i=0;

    struct Results* myResults = solution(N,A,M);

    printf("(");
    for (i=0; i<M; i++){
        printf("%d, ",*(myResults.C + i) );
    }
    printf(")\n");

    free (myResults.C);
    free (myResults);
    return 0;
}


