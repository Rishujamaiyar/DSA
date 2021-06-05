#include <bits/stdc++.h>
using namespace std;
//auto makes i not the pointer but the value of the DS

bool cycle(int i,map<int,bool> visited,map<int,bool> recstack,map <int ,list<int>> adj){
	
	if(visited[i]==false){
		visited[i]=true;
		recstack[i]=true;

		for(auto x:adj[i]){
             if(visited[x]==false && cycle(x,visited,recstack,adj))
             	return true;
             else if (recstack[x])
             	return true;
		}
	}
	recstack[i]=false;
	return false;
}

bool cycle_main(map <int ,list<int>> adj,int n){
map <int,bool> visited;
map <int,bool> recstack;

for(int i=0;i<n;i++){
	visited[i]=false;
	recstack[i]=false;
}

for(int i=0;i<n;i++)
	if(cycle(i,visited,recstack,adj))
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
  }

if(cycle_main(adj,n))
	cout<<"yes";
else
 cout<<"no";

    return 0; 

}