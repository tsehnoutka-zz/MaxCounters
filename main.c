#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct test{
    int N;  // number of iterators
    int M;  // Size of array
    int* A; // array of operations
    int* r; // expected result
};
typedef enum { false, true } bool;
#define  NumofTest 2
struct test myTest[NumofTest];
int tempA2[]={3, 5, 5, 1, 5};
int tempr2[]={2,2,2,2};
int tempA1[]={3,4,4,6,1,4,4};
int tempr1[]={3, 2, 2, 4, 2};
void setUpTest()
{
    myTest[0].N=4;
    myTest[0].A= tempA2;
    myTest[0].M= 5;
    myTest[0].r= tempr2;
    
    myTest[1].N=5;
    myTest[1].A=tempA1; 
    myTest[1].M= 7;
    myTest[1].r= tempr1;
    
    
}
struct Results {
  int * C;
  int L; // Length of the array
};


void printArray(int arr[], int n)
{
    int i=0;
    printf("(");
    for (i=0; i<n-1; i++)
      printf("%d, ", arr[i]);
    printf("%d)\n",arr[i] );
}

struct Results solution(int N, int A[], int M)
{
    struct Results result;
    
    int *B;
    B = (int *)calloc(N, sizeof(int));
    int max = 0;
    int lastIncrease = 0;
    for (int i = 0; i < M; i ++) {
        if(A[i] > 0 && A[i] < N + 1) {
            if (B[A[i] - 1] < lastIncrease) {
                B[A[i] - 1] = lastIncrease;
            }
            B[A[i] - 1] ++;
            if(max < B[A[i] - 1]) {
                max = B[A[i] - 1];
            }
        }
        if (A[i] == N + 1) {
            lastIncrease = max;
        }
    }
    
    for(int i = 0; i < N ; i ++) {
        if(B[i] < lastIncrease) {
            B[i] = lastIncrease;
        }
    }
    result.C = B;
    result.L = N;
    return result;
}
bool compareResults(struct Results result, struct test T){
    bool same=true;  // boolean: 0-false;  1-true
/*    
    printf("Compare Results test array - ");
    printArray(T.r,T.N); 
    printf("Compare Results Results array - ");
    printArray(myResults.C,myResults.L);     
*/    
    if (result.L != T.N){
        same= false;
    }
    else{
        int j =T.N-1;
        while ((j>=0)&& same){
            if (result.C[j] != T.r[j]){
                same=false;
            }
            j--;
        }
    }
    return true;
}

int main(int argc, char** argv) 
{
    int i=0;
    int arraySize=0;  
    
    setUpTest();
    
    for (i=0; i< NumofTest; i++){
        printf("Running test - %d\n", i);
        arraySize=sizeof(int) * myTest[i].N;
        
        struct Results result = solution(myTest[i].N,myTest[i].A,myTest[i].M);
         
        if (compareResults(result, myTest[i])){
            printf("PASS : ");
            printArray(myTest[i].r, myTest[i].N);
        }
        else{
            printf("FAIL\n");
        }
        free (result.C);
        printf("\n");
    }
    return 0;
}
