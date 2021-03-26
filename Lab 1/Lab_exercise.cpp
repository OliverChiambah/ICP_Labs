#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
//creating a struct to use in the inverse function
struct arrayPosition{
    int row;
    int col;
};
// Function signatures
int linearIndx(int i, int j);
int** createMatrix(int len);
int** createMatrixZeroes(int len);
void printMatrix(int** A, int len);
void printArray(int* A, int len);
int linearIndx(int row, int col, int len);
void majorFunction(int size);

arrayPosition InverseIdx(int n);

 

int main() { 

    // Calling the major function for the various numbers
    printf("Working with the case when the dimension is 8x8\n");
    majorFunction(8);
    printf("\n");


    printf("Working with the case when the dimension is 32x32\n");
    majorFunction(32);
    printf("\n");

    printf("Working with the case when the dimension is 128x128\n");
    majorFunction(128);
    printf("\n");

    return 0;
} 
//creating a matrix 
int** createMatrix(int len){
    int **A = new int* [len];
    for (int r= 0; r<len; r++)
        A[r] = new int[len];//creates the columns 

    srand(time(0));

    //using a for loop to fill the matrix
    for (int i = 0; i < len; i++){ 
        for (int j = 0; j < len; j++){ 
            if (i < j) { 
                A[i][j] = 0;
            }else{
                A[i][j] = (rand() % 1000)+1;//generating random numbers
            }   
        } 
    }
    return A;
}
//Creating a matrix to revert elements from the array back to their various positions.
int** createMatrixZeroes(int len){
    int **A = new int* [len];
    for (int r= 0; r<len; r++)
        A[r] = new int[len];//creates the columns 
    //using a for loop to fill the matrix
    for (int i = 0; i < len; i++){ 
        for (int j = 0; j < len; j++){ 
            A[i][j] = 0; 
        } 
    }
    return A;
}
// a function to print the first 20 elements of the original matrix and their respective indices
void printMatrix(int** A, int len){
    for (int i = 0; i < 6; i++){ 
        for (int j = 0; j < 5; j++){ 
            if (A[i][j] !=0)
            printf("A[%d][%d] = %d\n", i, j, A[i][j]);
        }        
       
    }
     printf("\n");
}
// A function to print the first 20 elements of the inverse of the matrix and their respective indices
void printinverseMatrix(int** C, int len){
    int count = 0;
    for (int i = 0; i < len; i++){ 
        for (int j = 0; j < len; j++){ 
            if (count < 20)
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
            count += 1;
        }        

    }
     printf("\n");
}

//printing the first 20 elements in the array with its respective indices in the brackets
void printArray(int* B, int len){
    for(int i = 0; i < 20; i++){
        printf("%d[%-i]  ", B[i], i); 
    }
}
// Linearindex function to iterate the lower triangular section of the matrix
int linearIndx(int row, int col){
    int sum = 0;
    for (int i = 1; i <= row; i++){
        sum += i;
    }
    sum = sum + col;
    return sum;
}
//The inverse function to revert the lower triangular matrix back to their various positions
arrayPosition InverseIdx(int n){
    // special case for n = 0
    if(n == 0){
        arrayPosition pos; 
        pos.row = 0;
        pos.col = 0;
        return pos;
    }
    int i = 1;
    int sum = 1;
    while((sum < n) && (n - sum > i)){
        i += 1;
        sum += i;
    }
    arrayPosition pos; 
    pos.row = i;
    pos.col = n - sum;
    return pos;
}
// A major funtion to combine all the other functions 
void majorFunction(int size){
    //Generating the array 
    int** arr = createMatrix(size);
    //printing the array
    printMatrix(arr, size);
    printf("\n\n");

    //copying lower triangular elements into an array 
    int y = (size * (size - 1))/2 + size;
    int* temp = (int *)malloc(y * (sizeof(int)));
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= i; j++){
            int t = linearIndx(i,j);
            temp[t] = arr[i][j];

        }
    }
    //print the elements in the array
    printArray(temp,y);
    printf("\n\n");
    //copying the elements in the array back to various positions
    int** arr2 = createMatrixZeroes(size);
    for(int i = 0; i < y; i++){
        arrayPosition pos = InverseIdx(i);
        arr2[pos.row][pos.col] = temp[i];
    }

    //print the second matrix 
    printinverseMatrix(arr2, size);
    printf("\n\n");

}