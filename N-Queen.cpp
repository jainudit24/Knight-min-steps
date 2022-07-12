// PROBLEM STATEMENT:
// The N Queen problem is the task of arranging N chess queens on a NxN 
// chessboard in such a way that no two queens attack each other.

// EXAMPLE:
// The expected result is a binary matrix with 1s for the blocks containing queens.
//The output matrix for the given 4 queen solution, for example, is as follows.
//               { 0,  1,  0,  0}
//               { 0,  0,  0,  1}
//               { 1,  0,  0,  0}
//               { 0,  0,  1,  0}

//APPROACH:
// The objective is to place queens in different columns one by one,
// starting with the leftmost column. We check for clashes with already
// placed queens when placing a queen in a column. If we locate a row in
// the current column with no collision, we mark that row and column as part
// of the solution. We backtrack and return false if we can't discover such
// a row due to clashes.


#include<iostream>
using namespace std;

// A utility function to check if a queen can
//    be placed on arr[x][y] where x->row and y->col
bool isSafe(int** arr, int x, int y, int n){
    for(int row=0; row<x; row++){
        if(arr[row][y]==1){ 
        return false;
      }
    }

  // check left diagonal position
  int row=x;
  int col=y;
  while(row>=0 && col>=0){
      if(arr[row][col]==1){
          return false;
      }
      row--;
      col--;
   }

  // check right diagonal position
  row=x;
  col=y;
  while(row>=0 && col<n){
      if(arr[row][col]==1){
          return false;
      }
      row--;
      col++;
  }
  return true;
}

bool nQueen(int** arr, int x, int n){

    if(x>=n){     // base case: when all queens are placed
        return true;
    }
    for(int col=0; col<n; col++){
        if(isSafe(arr,x,col,n)){
            //Place this queen in arr[x][col]
            arr[x][col]=1;
            
            //recur to place rest of the queens
            if(nQueen(arr,x+1,n)){
                return true;
            }
            //If placing queen in arr[x][col] doesn't lead to a solution, then
            //remove queen from arr[x][col] i.e. backtracking
            arr[x][col]=0;  
        }
    }
    return false;
}

int main()
{
    //n is the number of queens to be placed and size of board i.e. of arr is (n x n)
    int n;
    cout<<"Enter the number of Queens to be placed "<<endl;
    cin>>n;
    //2D array declaration dynamically
    int** arr=new int*[n];
    for(int i=0; i<n; i++){
        arr[i]=new int[n];
        for(int j=0; j<n; j++){
            //initialize the array to 0
            arr[i][j]=0;
        }
    }
    if(nQueen(arr,0,n)){
        //print the placed queens' position
        //in the output 2D array, 0 means empty position and 1 means filled position  
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}