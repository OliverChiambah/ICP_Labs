#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct arrayPosition{
    int row;
    int col;
};

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

    /*printf("Working with the case when the dimension is 128x128\n");
    majorFunction(128);
    printf("\n");*/

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

void printMatrix(int** A, int len){
    for (int i = 0; i < len; i++){ 
        for (int j = 0; j < len; j++){ 
            printf("%4d", A[i][j]); 
        } 
        printf("\n");
    }
}

void printArray(int* A, int len){
    for(int i = 0; i < 20; i++){
        printf("%d ", A[i]); 
    }
}

int linearIndx(int row, int col){
    int sum = 0;
    for (int i = 1; i <= row; i++){
        sum += i;
    }
    sum = sum + col;
    return sum;
}

arrayPosition InverseIdx(int n){
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

    int** arr2 = createMatrixZeroes(size);
    for(int i = 0; i < y; i++){
        arrayPosition pos = InverseIdx(i);
        arr2[pos.row][pos.col] = temp[i];
    }

    //print the second matrix 
    printMatrix(arr2, size);
    printf("\n\n");

}