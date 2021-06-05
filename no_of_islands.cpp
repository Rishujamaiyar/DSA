#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
bool visited[101][101];


bool valid(int n,int m,int i,int j){
    return (i>=0 && i<n && j>=0 && j<m && arr[i][j] && !visited[i][j]);
}
void dfs(int n,int m,int i,int j){
    static int dx[] = {-1,-1,-1,0,0,1,1,1};
    static int dy[] = {-1,0,1,-1,1,-1,0,1};
    
    visited[i][j] = true;
    for(int a=0;a<8;a++){
        if(valid(n,m,i+dx[a],j+dy[a])){
            dfs(n,m,i+dx[a],j+dy[a]);
        }
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && arr[i][j]){
             dfs(n,m,i,j);   
             count++;
            }
            
        }
    }
        
        cout<<"The no of islands are:"<<count<<endl;
        
        
    }
}