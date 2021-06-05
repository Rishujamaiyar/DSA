#include <bits/stdc++.h>
using namespace std;
#define n 5
bool valid(int x,int y,int M[n][n]){
    return (x >= 0 && x < n && y>=0 && y < n && M[x][y]==1);
}

bool func(int soln[n][n],int M[n][n],int x,int y){
  //base case
  if(x==n-1 && y==n-1 && M[n][n]==1){
    soln[x][y]=1;
    return true;
  }

  if(valid(x,y,M)){
    //updating this step
    soln[x][y]=1;
    //way1
    if(func(soln,M,x+1,y))
    return true;
    //way2
    if(func(soln,M,x,y+1))
    return true;
    //backtracking reversing the update made
    soln[x][y]=0;
    return false;
  }
  return false;

}

int main(){
	int t;
	cin>>t;
	while(t--){
    //input
        int M[n][n];
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        	   cin>>M[i][j];
            }
        }
    //process
    int soln[n][n]={0};
    
    
    if(func(soln,M,0,0))
      cout<<"true"<<endl;

    else
      cout<<"false"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<soln[i][j]<<" ";
      }
      cout<<endl;
    }


}}
