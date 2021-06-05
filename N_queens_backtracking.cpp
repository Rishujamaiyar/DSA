
#include<bits/stdc++.h> 
using namespace std; 
int N;
int board[10][10];
void printSolution(int N) 
{ 
	cout<<"[";
	for(int j=0;j<N;j++)
	for(int i=0;i<N;i++)
			if(board[i][j])
				cout<<i+1<<' ';
	cout<<"]";
} 


bool isSafe(int N, int row, int col) 
{ 
	int i, j; 
	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 


	for (i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

bool solveNQUtil(int N, int col) 
{ 

	if (col == N){ 
		printSolution(N); 
		return true; 
	} 

	bool res = false; 
	for (int i = 0; i < N; i++){ 
		if ( isSafe(N, i, col) ){ 
			board[i][col] = 1; 
			res = solveNQUtil(N, col + 1) || res; 
			board[i][col] = 0; 
		} 
	} 
	return res; 
} 


int main() 
{ int t;
	cin>>t;
	while(t--){
 cin>>N;
	memset(board, 0, sizeof(board)); 

	if (solveNQUtil(N, 0) == false) 
		printf("-1"); 
cout<<endl;	
		}

   
	return 0; 
} 
