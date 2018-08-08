#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Results {
  int * C;
  int L; // Length of the array
};
struct Results myResults;

void printC(int arr[], int n)
{
    printf("printC -" );
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
    printf("\n");
}
void printArray()
{   
    int i=0;
    printf("(");
    for (i=0; i<myResults.L; i++){
        printf("%d, ",*(myResults.C + i) );
    }
    printf(")\n");
}

struct Results solution(int N, int A[], int M)
{
    int i=0,j=0;
    int max=0;
    int arraySize=sizeof (int) *N;

    for (i=0; i<M; i++){
        if (A[i] == N+1){
            max++;
            for (j=0; j<N; j++){
                myResults.C[j]=max;
            }
            printf("inLoop(%d) - ",max);
            printArray();       
        }
        else{

            int temp = (myResults.C[A[i]-1])++;
            //printf("temp - %d\n",temp);
            if (temp > max ){
                max = temp;
            }
            printf("inLoop(%d) - ",max);
            printArray();       
        }
    }
    return myResults;
}


int main(int argc, char** argv) {
    int N=5;
    int A[7] = {3,4,4,6,1,4,4};
    int M = 7;
    int i=0;
    int arraySize=sizeof (int) *N;
    myResults.C = malloc(arraySize);
    memset(myResults.C,0,arraySize);
    myResults.L=N;
    
    //printC(myResults.C,myResults.L);
    
    myResults = solution(N,A,M);

    printArray();

    free (myResults.C);

    return 0;
}


