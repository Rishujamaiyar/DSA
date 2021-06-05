#include <bits/stdc++.h>
using namespace std;
//auto makes i not the pointer but the value of the DS

void dfs(int x,map<int,list<int>> adj,bool visited[]){
	visited[x]=true;
	cout<<x<<" ";

	for(auto i:adj[x])
		if(!visited[i])
			dfs(i,adj,visited);


}





int main(){
map <int ,list<int>> adj;
int u,v;
int t,n;
cin>>t>>n;
  for(int i=0;i<t;i++){
  	cin>>u>>v;
  	adj[u].push_back(v);
  }
  bool visited[n]={false};
  dfs(1,adj,visited);
    return 0; 

}