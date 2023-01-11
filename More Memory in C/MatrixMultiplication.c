#include <stdio.h>
#include <stdlib.h>
int** matMult(int **a, int **b, int size) {
// (4) Implement your matrix multiplication here. You will need to create a 
new matrix to store the product.
    int ** new_matrix_array = (int**)malloc(size * sizeof(int*));
    int sum = 0;
    for (int i = 0; i < size; i++){
        *(new_matrix_array + i) = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++){
            sum = 0;
            for(int k = 0; k < size; k++){
                sum += *(*(a + i) + k) * *(*(b + k) + j);
            }
            *(*(new_matrix_array + i) + j) = sum;
        }
    }
    
    return new_matrix_array;
}
void printArray(int **arr, int n) {
// (2) Implement your printArray function here
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", *(*(arr+i) + j));
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    int n = 5;
// (1) Define 2 (n x n) arrays (matrices). 
    int ** matA = (int**)malloc(n * sizeof(int*));
    int ** matB = (int**)malloc(n * sizeof(int*));
    int ** matC;
    
    
    for (int i = 0; i < n; i++){
        *(matA + i) = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            *(*(matA + i) + j) = ((i + 1) * (j + 1));
        }
    }
    
    for (int i = 0; i < n; i++){
        *(matB + i) = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            *(*(matB + i) + j) = ((n - i) * (n - j));
        }
    }
    
    
// (3) Call printArray to print out the 2 arrays here.
    printArray(matA, n);
    printArray(matB, n);
// (5) Call matMult to multiply the 2 arrays here.
    matC = matMult(matA, matB, n);
// (6) Call printArray to print out resulting array here.
    printArray(matC, n);
    return 0;
}// (3) Call printArray to print out the 2 arrays here.
    printArray(matA, n);
    printArray(matB, n);
// (5) Call matMult to multiply the 2 arrays here.
    matC = matMult(matA, matB, n);
// (6) Call printArray to print out resulting array here.
    printArray(matC, n);
    return 0;
}
