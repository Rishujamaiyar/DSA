#include <bits/stdc++.h>
using namespace std;

bool valid(int x,int y,int N){
    if(x>=0 && x < N && y>=0 && y < N )
      return true;
    return false;
}
bool bfs(map<int,list<int>> adj,int k,int s,int d,int N){
      bool visited[N*N+2]={0};
      
      queue <int> q;
      q.push(s);
      while(!q.empty()){
          int s = q.front();
          q.pop();
          for(auto x:adj[s]){
              if(x==d)
              return true;
              if(!visited[x]){
                visited[x] = true;
                q.push(x);
              }
          }
          
      }
      return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
        int M[N][N];
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
        	    int x;
        	    cin>>x;
               M[i][j] = x;
            }
        }

    map <int,list<int>> adj;
    int k=1;
    int s=0,d=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(M[i][j]){
                if(valid(i+1,j,N) && M[i+1][j]){
                   adj[k].push_back(k+N);
                }
                if(valid(i-1,j,N) && M[i-1][j]){
                    adj[k].push_back(k-N);
                }
                if(valid(i,j+1,N) && M[i][j+1]){
                    adj[k].push_back(k+1);
                }
                if(valid(i,j-1,N) && M[i][j-1]){
                    adj[k].push_back(k-1);
                }
                
                if(M[i][j]==1) s=k;
                if(M[i][j]==2) d=k;
                
            }k++;
        }    
    }
   
if(bfs(adj,k,s,d,N)) cout<<"1"<<endl;
else cout<<"0"<<endl;
}}
