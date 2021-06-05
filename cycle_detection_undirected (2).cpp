#include <bits/stdc++.h>
using namespace std;
//auto makes i not the pointer but the value of the DS

bool cycle(int i,int parent,map<int,bool> visited,map <int ,list<int>> adj){
	visited[i]=true;

	for(auto x:adj[i]){
		if(visited[x]==false)
			{if(cycle(x,i,visited,adj))
			return true;}
		else if(x!=parent)
			return true;
	}

	return false;
}

bool cycle_main(map <int ,list<int>> adj,int n){
map <int,bool> visited;

for(int i=0;i<n;i++){
	visited[i]=false;
}

for(int i=0;i<n;i++)
	if(visited[i]==false)
	  if(cycle(i,-1,visited,adj))
		return true; 
		

return false;
}


int main(){
map <int ,list<int>> adj;
int u,v;
int t,n;
cin>>t>>n;
  for(int i=0;i<t;i++){
  	cin>>u>>v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }

if(cycle_main(adj,n))
	cout<<"yes";
else
 cout<<"no";

    return 0; 

}