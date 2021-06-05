#include <bits/stdc++.h>
using namespace std;
#define ROW 5 
#define COL 4 


void func(int matrix[ROW][COL]){
  int sy;
  int sx;
   for(int i=0;i<ROW+COL-1;i++){
    sx=0;
    

  }
}

void printMatrix(int matrix[ROW][COL]) 
{ 
    for (int i=0; i< ROW; i++) 
    { 
        for (int j=0; j<COL; j++) 
            printf("%5d ", matrix[i][j]); 
        printf("\n"); 
    } 
} 



int main() 
{ 
    int M[ROW][COL] = {{1, 2, 3, 4}, 
                       {5, 6, 7, 8}, 
                       {9, 10, 11, 12}, 
                       {13, 14, 15, 16}, 
                       {17, 18, 19, 20}, 
                      }; 
   printMatrix(M);
    return 0; 
} 