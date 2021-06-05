#include <bits/stdc++.h>
using namespace std;

bool visited[500]={0};


void dfs(vector<int> adj[],int i){
	visited[i] = true;
	for(auto x:adj[i]){
		if(!visited[x])
			dfs(adj,x);
	}
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	//input
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}	

	int v=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(adj,i);
			v=i;
		}
	}
    //cout<<v;

	for(int i=0;i<n;i++)
		visited[i] = false;
	dfs(adj,v);
	for(int i=0;i<n;i++)
		if(!visited[i])
			cout<<-1;
		cout<<v;



	}


}